#include "sql.h"

//set number of commands for session equal to zero
SQL::SQL()
{
    commNum = 0;
}

void SQL::run()
{
    vector<string> RPN;
    bool debug = false;

    while(1)
    {
        try
        {
            //get a command
            string line;
            cout<<"Command: ";
            getline(cin, line);
            fflush(stdin);

            char command[line.size()];
            strcpy(command, line.c_str());

            //exit if line == exit
            if(line == "exit")
            {
                cout << "THANK YOU!" << endl;
                exit(0);
            }

            //parse the command, and get ptree
            Parser temp(command);
            ptree = temp.get_parse_tree();

            //do shunting yard if select->values
            if(ptree["command"][0] == "select" &&
                    !ptree["values"].empty())
            {
                //shunting yard
                RPN = temp.shuntingYard();
            }

            //Creating table
            if(ptree["command"][0] == "create"
                    || ptree["command"][0] == "make")
            {
                //create table with fields given
                Table t(ptree["table_name"][0], ptree["fields"]);

                //output to terminal
                display_create(line);
                commNum++;
            }

            //inserting into table
            else if(ptree["command"][0] == "insert")
            {
                //table already exists
                Table t(ptree["table_name"][0]);
                t.insert(ptree["values"]);

                //output to terminal
                display_insert(line);
                commNum++;
            }
            //selecting records from table
            else if(ptree["command"][0] == "select")
            {
                Table t(ptree["table_name"][0]);
                if(ptree["fields"][0] == "*")
                {
                    if(!ptree["values"].empty())
                    {
                        //take in RPN, evaluate it and display it
                        Table temp = t.select_all(RPN);
                        display_select_all(command, temp);
                        //clear up the files from temp table
                        temp.clean_up();
                    }
                    else
                    {
                        //select all records in table
                        //and display them
                        Table temp = t.select_all();
                        display_select_all(command, temp);
                        //clean up temp table
                        temp.clean_up();
                    }

                    //add ones to commandnum
                    commNum++;
                }
            }
            //run a batch file
            else if(ptree["command"][0] == "batch")
            {
                run_batch(ptree["file_name"][0]);
            }

        }
        catch (exception &e)
        {
            cout << e.what() << endl << endl;
        }
        catch (...)
        {
            cout << endl << "An unknown error has occured." << endl << endl;
        }
    }
}


void SQL::run_batch(string filename)
{
    bool debug = false;
    fstream f;
    fstream g;
    string line = "";
    vector<string> RPN;

    //OUTPUT BATCH RESULT TO TXT FILE AS WELL
    string output = filename;
    if(filename.find('.') > filename.size())
         filename += ".txt";
    t_open_fileRW(f, filename.c_str());
    output += "_output.txt";
    t_open_fileRW(g, output.c_str());

    while(getline(f, line))
    {
        try
        {
            //if our line does not start with an m, i, or s
            if(line[0]!= 'm' && line[0]!= 'i' && line[0]!= 's')
            {
                //output to console and text file
                cout << line << endl;
                g << line << endl;
                continue;
            }
            else
            {
                char command[line.size()];
                strcpy(command, line.c_str());

                //if parser is invalid(ends in an invalid state),we must continue
                Parser temp(command);
                ptree = temp.get_parse_tree();

                //do shunting yard if select->values
                if(ptree["command"][0] == "select" &&
                        !ptree["values"].empty())
                {
                    //shunting yard
                    RPN = temp.shuntingYard();
                }

                if(ptree["command"][0] == "create" || ptree["command"][0] == "make")
                {
                    //create table with fields given
                    Table t(ptree["table_name"][0], ptree["fields"]);

                    //output to terminala and file
                    display_create(line);
                    display_create(line, g);
                    commNum++;
                }
                else if(ptree["command"][0] == "insert")
                {
                    //table already exists
                    Table t(ptree["table_name"][0]);
                    t.insert(ptree["values"]);

                    //output to terminala and file
                    display_insert(line);
                    display_insert(line, g);
                    commNum++;
                }
                else if(ptree["command"][0] == "select")
                {
                    Table t(ptree["table_name"][0]);
                    if(ptree["fields"][0] == "*")
                    {
                        if(!ptree["values"].empty())
                        {
                            //take in RPN, evaluate it and display it
                            Table temp = t.select_all(RPN);
                            display_select_all(command, temp);
                            display_select_all(command, temp, g);
                            //clear up the files from temp table
                            temp.clean_up();
                        }
                        else
                        {
                            //select all records in table
                            //and display them
                            Table temp = t.select_all();
                            display_select_all(command, temp);
                            display_select_all(command, temp, g);
                            //clean up temp table
                            temp.clean_up();
                        }
                        //add ones to commandnum
                        commNum++;
                    }
                }
                //run a batch file
                else if(ptree["command"][0] == "batch")
                {
                    run_batch(ptree["file_name"][0]);
                }
            }
        }
        catch (exception &e)
        {
            cout << e.what() << endl << endl;
            g << e.what() << endl << endl;
        }
        catch (...)
        {
            cout << endl << "An unknown error has occured." << endl << endl;
            g << endl << "An unknown error has occured." << endl << endl;
        }
    }
    cout << "---------------------------" << endl;
    cout << "End of Batch Process" << endl;
    g << "---------------------------" << endl;
    g << "End of Batch Process" << endl;
    f.close();
    g.close();
}

//displays a message after create
void SQL::display_create(string command, ostream& outs)
{
    outs << "[" << commNum << "] ";
    outs << command << endl;
    outs << "Table Created: " << ptree["table_name"][0] << endl << endl << endl;

    outs << "SQL: DONE." << endl << endl;
}

//displays a message after insert
void SQL::display_insert(string command, ostream& outs)
{
    outs << "[" << commNum << "] ";
    outs << command << endl;
    outs << "SQL::run: inserted into table: " << ptree["table_name"][0] << endl << endl << endl;

    outs << "SQL: DONE." << endl << endl;
}

//displays a message after select all
void SQL::display_select_all(string command, Table t, ostream& outs)
{
    outs << "[" << commNum << "] ";
    outs << command << endl << endl;

    outs << t << endl << endl;
    outs << "SQL: DONE." << endl << endl;
}



//checks if a text file exists
bool SQL::t_file_exists(string file_name)
{
    const bool debug = false;
    fstream ff;
    ff.open (file_name,
        std::fstream::in);
    if (ff.fail()){
        if (debug) cout<<"file_exists(): File does NOT exist: "<<file_name<<endl;
        return false;
    }
    if (debug) cout<<"file_exists(): File DOES exist: "<<file_name<<endl;
    ff.close();
    return true;
}

//Post: opens a text file for reading and writing
void SQL::t_open_fileRW(fstream& f, const string file_name)
{
    const bool debug = false;
    if (!t_file_exists(file_name)){
        f.open(file_name, std::fstream::out);
        if (f.fail()){
            cout<<"file open (RW) failed: with out|"<<file_name<<"]"<<endl;
            throw("file RW failed  ");
        }
        else{
            if (debug) cout<<"open_fileRW: file created successfully: "<<file_name<<endl;
        }
    }
    else{
        //opens for input and output
        f.open (file_name,
            std::fstream::in | std::fstream::out);
        if (f.fail()){
            cout<<"file open (RW) failed. ["<<file_name<<"]"<<endl;
            throw("file failed to open.");
        }
    }
}

