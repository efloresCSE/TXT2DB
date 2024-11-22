#ifndef TEST_FUNCTIONS_H
#define TEST_FUNCTIONS_H

#include "parser.h"
#include "record.h"
#include "table.h"
#include "sql.h"
#include "ftokenizer.h"

MMap<string, long> mmap_get_word_indices(char* file_name)
{
    const bool debug = false;
    MMap<string, long> word_indices;
    FTokenizer ftk("solitude.txt");
    Token t;
    long count = 0;

    ftk >> t;
    while (ftk.more()){
        //only the "words"
        if (t.type_string() == "ALPHA"){
            string s;
            s = t.token_str();
            word_indices[s] += count;
            count++;
            if (debug)
                cout<<"|"<<t.token_str()<<"|"<<endl;
        }
        ftk >> t;
    }
    return word_indices;
}

int mmapTester()
{

    const int border_length = 70;
    const string border(border_length, '*');

    //push output down
    cout << endl << endl << endl;
    cout << border << endl;
    cout << "          M U L T I M A P    T E S T"
         << endl;

    MMap<string, long> word_indices;
    word_indices = mmap_get_word_indices("solitude.txt");
    cout<<endl<<endl<<endl;

    //list all nodes of the index mmap:
    for (MMap<string, long>::Iterator it = word_indices.begin();
         it != word_indices.end(); it++){
        cout<<*it<<endl;
    }


    cout<<endl<<endl<<endl;
    cout<<"---------------------------------------------------"<<endl;
    string this_word = "ice";
    cout<<"---------------------------------------------------"<<endl;
    cout<<"Indices of \""<<this_word<<"\""<<endl;
    //list indices of this_word:
    if (word_indices.contains(this_word)){
        cout<<this_word<<": "<<word_indices[this_word]<<endl;
    }
    cout<<endl<<endl<<endl;

    //list indeces between two indexs
    cout<<"---------------------------------------------------"<<endl;
    string from = "ask";
    string to = "cold";
    //list from .. to:
    cout<<"listing indices from \""<<from<<"\" to \""<<to<<"\""<<endl;
    cout<<"---------------------------------------------------"<<endl;
    for (MMap<string, long>::Iterator it =
                word_indices.lower_bound(from);
         it != word_indices.upper_bound(to) &&
         it != word_indices.end(); it++){
        cout<<*it<<endl;
    }

    cout <<endl<<endl<<endl<< "========== E N D  ====================" << endl;
    return 0;
}

#endif // TEST_FUNCTIONS_H
