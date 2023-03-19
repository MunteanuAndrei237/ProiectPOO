#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;


class Screen
{
    int height;
    int width;
public:
    Screen (int h,int w): height{h}, width{w} {}
    Screen(const Screen& other) : height{other.height}, width{other.width} {}
    Screen& operator=(const Screen& other)
    {
        height = other.height;
        width = other.width;
        return *this;
    }
    ~Screen(){};
    friend std::ostream& operator<<(std::ostream& os, const Screen& a) {
        os << "height: " << a.height << ", width: " << a.width << "\n";
        return os;
        }
};
class Gamemode
{
    string gamemode;
    vector<string> icons;
    vector<float> weights;
    int rows;
    int columns;
public:
    Gamemode(string gs): gamemode{gs}
    {
        if(gamemode=="classic")
        {
            weights= {0.25,0.2,0.2,0.05,0.05,0.3};
            icons= {"cherry","orange","banana","seven","crown","melon"};
            rows=3;
            columns=5;
        }
        else if (gamemode=="book_of_ra")
        {
            weights= {0.25,0.25,0.2,0.05,0.05,0.25};
            icons= {"A","Q","K","book","pharaoh","J"};
            rows=3;
            columns=5;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Gamemode& a) {
        os << "gamemode: " << a.gamemode << ", icons:[ ";
        for(int i=0;i<a.icons.size();i++)
        os<< a.icons[i]<<", ";
        os<<"], weights:[ ";
        for(int i=0;i<a.weights.size();i++)
        os<< a.weights[i] <<", ";
        os<<"]\n";
        return os;
        }
    int getRows() {
      return rows;
    }
int getColumns() {
      return columns;
    }
vector<string> getIcons() {
      return icons;
    }
vector<float> getWeights() {
      return weights;
    }
};

class Hud
{
    float balance=0;
    int total_inserted=0;
public:
    friend std::ostream& operator<<(std::ostream& os, const Hud& a) {
        os << "balance: " << a.balance << ", totalinserted: " << a.total_inserted << "\n";
        return os;
        }
    void insert_balance(int b)
    {
        cout<<"You inserted "<<b<<"$"<<endl;
        balance+=b;
        total_inserted+=b;
    }
    void double_the_win(int win,string culoare)
    {
        balance-=win;
        srand(time(NULL));
        int ch=rand();
            if (ch%2==0)
                {cout<<"You won:"<<win<<endl;
                win*=2;}
            else
                {cout<<"You lost:"<<win<<endl;
                win=0;}
        balance+=win;
    }

    void cashout()
    {
        cout<<"Money inserted:"<<total_inserted<<endl;
        cout<<"Money out:"<<balance<<endl;
        cout<<"Profit:"<<balance-total_inserted<<endl;
    }
    void play(int b,Gamemode g)
    {
    balance-=b;
    vector<vector<string>> t=generate_table(g.getRows(),g.getColumns(),g.getWeights(),g.getIcons());
    int m=calculate_multiplier(t,g.getRows(),g.getColumns(),g.getWeights(),g.getIcons());
    balance+=m*b;
    cout<<"you multiplied your $"<<b<<"by:"<< m<<endl;
    }
    vector<vector<string>> generate_table(int rows,int columns,vector<float> weights,vector<string> icons)
    {
        vector<vector<string>> table(rows , vector<string> (columns));
        srand(time(NULL));
        int columnindex=0;
        int rowindex=0;
        for (int rowindex=0;rowindex<rows;rowindex++)
            for (int columnindex=0;columnindex<columns;columnindex++)
            {
                float ch=float(rand()%100)/100;
                float weighttotal=0;
                int i=0;
                while(weighttotal<=ch)
                {
                    weighttotal=weighttotal+weights[i];
                    i+=1;
                }
                table[rowindex][columnindex]=icons[i-1];
            }

        /*for(int i=0;i<rows;i++)
            {for(int j=0;j<columns;j++)
                cout<<table[i][j]<<" ";
            cout<<endl;
            }*/
        return table;
    }
    int calculate_multiplier(vector<vector<string>> t,int rows,int columns,vector<float> weights,vector<string> icons)
    {
        float multiplier=0;

        for(int i=0;i<rows;i++)
            for(int j=0;j<columns-2;j++)
                {
                if(t[i][j]==t[i][j+1] && t[i][j+1]==t[i][j+2])
                    {for(int k=0;k<icons.size();k++)
                        if(icons[k]==t[i][j])
                            multiplier+=float(1/weights[k]);
                }
        for(int i=0;i<rows-2;i++)
            for(int j=0;j<columns-2;j++)
                if(t[i][j]==t[i+1][j+1] && t[i+1][j+1]==t[i+2][j+2])
                {for(int k=0;k<icons.size();k++)
                        if(icons[k]==t[i][j])
                            multiplier+=float(1/weights[k])*1.3;
                }
        return multiplier;
    }
    }

};


int main()
{
    Screen screen1(1080,1920);
    Gamemode g1("classic");
    Hud hud1;
    hud1.insert_balance(200);
    hud1.play(10,g1);
    hud1.double_the_win(10,"Negru");
    hud1.cashout();
    return 0;
}
