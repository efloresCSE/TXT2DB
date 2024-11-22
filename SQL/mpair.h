#ifndef MPAIR_H
#define MPAIR_H
#include "mylib.h"

using namespace std;

template <typename K, typename V>
struct MPair{
    K key;
    vector<V> value_list;

    //------------------------------------------------------------------
    /*      MPair CTORs:
     *  must have these CTORs:
     *
     *  - default CTOR / CTOR with a key and no value: this will
     *  create an empty vector
     *
     *  - CTOR with a key AND a value: pushes the value into
     *  the value_list
     *
     *  _ CTOR with a key and a vector of values (to replace value_list)
     */
    //------------------------------------------------------------------
    MPair(const K& k=K())
    {
        key = k;
        value_list = vector<V>();
    }

    MPair(const K& k, const V& v)
    {
        key = k;
        value_list = vector<V>();
        //value_list.push_back(v);
    }

    MPair(const K& k, const vector<V>& vlist)
    {
        key = k;
        value_list = vector<V>();
        value_list = vlist;
    }

    //---------------------------------------------------------------

    //You'll need to overload << for your vector:
    //overloaded insertion operator
    friend ostream& operator <<(ostream& outs,
                                const MPair<K, V>& print_me)
    {
        //for sql
        for(int i = 0; i < print_me.value_list.size(); ++i)
        {
            outs << print_me.value_list[i] << " ";
        }

//        //for mmap test
//        outs << "[" << print_me.key << "|{";
//        for(int i = 0; i < print_me.value_list.size(); ++i)
//        {
//            outs << print_me.value_list[i];
//            if(i < print_me.value_list.size()-1)
//                outs << ",";
//        }
//        outs << "}]";
        return outs;
    }

//    void get_values(){return value_list;}

    //overloaded comparison operator
    friend bool operator ==(const MPair<K, V>& lhs,
                            const MPair<K, V>& rhs)
    {
        if(lhs.key == rhs.key)
            return true;
        return false;
    }
    friend bool operator !=(const MPair<K, V>& lhs,
                            const MPair<K, V>& rhs)
    {
        if(lhs.key != rhs.key)
            return true;
        return false;
    }

    //overloaded comparison operator
    friend bool operator < (const MPair<K, V>& lhs,
                            const MPair<K, V>& rhs)
    {
        if(lhs.key < rhs.key)
            return true;
        return false;
    }

    //overloaded comparison operator
    friend bool operator <= (const MPair<K, V>& lhs,
                             const MPair<K, V>& rhs)
    {
        if(lhs.key <= rhs.key)
            return true;
        return false;
    }

    //overloaded comparison operator
    friend bool operator > (const MPair<K, V>& lhs,
                            const MPair<K, V>& rhs)
    {
        if(lhs.key > rhs.key)
            return true;
        return false;
    }

    //overloaded comparison operator
    friend bool operator >= (const MPair<K, V>& lhs,
                             const MPair<K, V>& rhs)
    {
        if(lhs.key >= rhs.key)
            return true;
        return false;
    }
    friend MPair<K, V> operator + (const MPair<K, V>& lhs,
                                   const MPair<K, V>& rhs);
    //overloaded addition operator
    //push entry into lhs vector
    friend MPair<K, V> operator += (const MPair<K, V>& lhs,
                                  const MPair<K, V>& rhs)
    {

        MPair<K, V> temp = lhs;
        temp.value_list += rhs.value_list[0];

        return temp;
    }
};
#endif // MPAIR_H
