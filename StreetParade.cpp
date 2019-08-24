#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    while(true)				
    {
        int size; 
        cin >> size;
        if(size == 0)															// breaking loop after 0 is scanned
        {
            break;
        }

        int checkerArr[size];
        for(int i = 0 ; i < size ; i++)
        {
            cin >> checkerArr[i];													// scanning all elements;
        }

        int finalArr[size]; int index = 0;
        stack<int> st;

        for(int i = 0 ; i < size ; i++)
        {
            if(st.empty())														// first element always goes in stack
            {
                st.push(checkerArr[i]);
            }    


            else if( st.top() > checkerArr[i])									
            {
                st.push(checkerArr[i]);
            }


            else
            {
                while( !st.empty() && st.top() < checkerArr[i])				
                {
                    finalArr[index++] = st.top();
                    st.pop();
                }
                st.push(checkerArr[i]);
            }
        }
        while( !st.empty() )													// checking for remaining elements in stack
        {
            finalArr[index++] = st.top();
            st.pop();
        }

        int flag = 0;
        for(int i = 0 ; i < size-1 ; i++)										// checking final order
        {
            if(finalArr[i] > finalArr[i+1])
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)															// printing outcome
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    return 0;
}