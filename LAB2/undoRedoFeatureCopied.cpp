#include<iostream>
#include<stack>
#include<string>

using namespace std;

class undoRedoFeature{
    private:
        string data;
        stack<pair<int,int>> curr,trash;
    public:
        void changeCase(int i,int j) {

            for (int k=i; k<=j; k++)
            {
                if (isupper((this-> data)[k])) 
                    (this-> data)[k] = (this-> data)[k] + 32;
                else if(islower((this-> data)[k]))
                    (this-> data)[k] = (this-> data)[k] - 32;
            }
            (curr).push({i,j});
        }
        void undo() {
            if(!curr.empty())
            {
                (this-> trash).push(curr.top());
                for (int k=curr.top().first; k<=curr.top().second; k++)
                {
                    if (isupper((this-> data)[k])) 
                        (this-> data)[k] = (this-> data)[k] + 32;
                    else if(islower((this-> data)[k]))
                        (this-> data)[k] = (this-> data)[k] - 32;
                }
                (this-> curr).pop();
            }
        }
        void redo() {
            if(!trash.empty())
            {
                (curr).push((this-> trash).top());
                for (int k=trash.top().first; k<=trash.top().second; k++)
                {
                    if (isupper((this-> data)[k]))
                        (this-> data)[k] = (this-> data)[k] + 32;
                    else if(islower((this-> data)[k]))
                        (this-> data)[k] = (this-> data)[k] - 32;
                }
                (this-> trash).pop();
            }
        }
        void init(string s) {
            this-> data= s;
            while(!curr.empty())
            {
                curr.pop();
            }
        }
        void display() {
            cout<<data<<endl;
        }
        void clears() {
            while(!trash.empty())
            {
                trash.pop();
            }
        }
};

int main(){
    int t;
    cin>>t;
    int code;
    string s;
    undoRedoFeature urf;
    for(int q=0;q<t;q++){
        cin>>code;
        switch(code)
        {
            case 1:
                cin>>s;
                urf.init(s);
                urf.clears();
                break;
            case 2:
                int i,j;
                cin>>i>>j;
                urf.changeCase(i,j);
                urf.clears();
                break;
            case 3:
                urf.undo();
                break;
            case 4:
                urf.redo();
                urf.clears();
                break;
            case 5:
                urf.display();
                break;
        }
    }
}