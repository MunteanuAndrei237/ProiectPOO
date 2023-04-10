#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Gamemode {
    string gamemode;
    vector<string> icons;
    vector<double> weights;
    int rows;
    int columns;
public:
    Gamemode(const string &gs) : gamemode{gs} {
        if (gamemode == "classic") {
            weights = {0.25, 0.2, 0.2, 0.05, 0.05, 0.3};
            icons = {"cherry", "orange", "banana", "seven", "crown", "melon"};
            rows = 3;
            columns = 5;
        } else if (gamemode == "book_of_ra") {
            weights = {0.25, 0.25, 0.2, 0.05, 0.05, 0.25};
            icons = {"A", "Q", "K", "book", "pharaoh", "J"};
            rows = 3;
            columns = 5;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Gamemode &a) {
        os << "gamemode: " << a.gamemode << ", icons:[ ";
        for (unsigned int i = 0; i < a.icons.size(); i++)
            os << a.icons[i] << ", ";
        os << "], weights:[ ";
        for (unsigned int i = 0; i < a.weights.size(); i++)
            os << a.weights[i] << ", ";
        os << "]\n";
        return os;
    }
    vector<vector<string>> generate_table() {
        vector<vector<string>> table(rows, vector<string>(columns));
        for (int rowindex = 0; rowindex < rows; rowindex++)
            for (int columnindex = 0; columnindex < columns; columnindex++) {
                float ch = float(rand() % 100) / 100;
                float weighttotal = 0;
                int ind = 0;
                while (weighttotal <= ch) {
                    weighttotal = weighttotal + weights[ind];
                    ind += 1;
                }
                if (ind != 0)
                    table[rowindex][columnindex] = icons[ind - 1];
            }
        for(int i=0;i<rows;i++)
            {for(int j=0;j<columns;j++)
                cout<<table[i][j]<<" ";
            cout<<endl;
            }
        return table;
    }
    int calculate_multiplier(vector<vector<string>> t) {
        float multiplier = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns - 2; j++)
                if (t[i][j] == t[i][j + 1] && t[i][j + 1] == t[i][j + 2]) {
                    for (unsigned int k = 0; k < icons.size(); k++)
                        if (icons[k] == t[i][j])
                            multiplier += float(1 / weights[k]);
                }
        for (int i = 0; i < rows - 2; i++)
            for (int j = 0; j < columns - 2; j++)
                if (t[i][j] == t[i + 1][j + 1] && t[i + 1][j + 1] == t[i + 2][j + 2]) {
                    for (unsigned int k = 0; k <icons.size(); k++)
                        if (icons[k] == t[i][j])
                            multiplier += float(1 / weights[k]) * 1.3;
                }
        return multiplier;
    }
};

class Hud {
    float balance = 0;
    int total_inserted = 0;
public:
    friend std::ostream &operator<<(std::ostream &os, const Hud &a) {
        os << "balance: " << a.balance << ", totalinserted: " << a.total_inserted << "\n";
        return os;
    }

    void insert_balance(int b) {
        cout << "You inserted " << b << "$" << endl;
        balance += b;
        total_inserted += b;
    }

    void double_the_win(int win, const string &culoare) {
        balance -= win;
        int ch = rand();
        if (ch % 2 == 0) {
            if (culoare == "black")
                cout << "Black.";
            else
                cout << "Red.";
            cout << "You won:" << win << endl;
            win *= 2;
        } else {
            if (culoare == "black")
                cout << "Red.";
            else
                cout << "Black.";
            cout << "You lost:" << win << endl;
            win = 0;
        }
        balance += win;
    }

    void cashout() {
        cout << "Money inserted:" << total_inserted << endl;
        cout << "Money out:" << balance << endl;
        cout << "Profit:" << balance - total_inserted << endl;
    }

    void play(int b, Gamemode g) {
        balance -= b;
        vector<vector<string>> t = g.generate_table();
        int m = g.calculate_multiplier(t);
        balance += m * b;
        cout << "you multiplied your $" << b << " by: " << m << endl;
    }

};

class Screen {
    int height;
    int width;
    Hud hud;
    Gamemode sgamemode;
public:
    Screen(int h, int w, Hud hud_,const string &gamemodegs) : height{h}, width{w} ,hud{hud_}, sgamemode{gamemodegs} {};

    Screen(const Screen &other): height{other.height}, width{other.width} ,sgamemode{other.sgamemode} {};

    Screen &operator=(const Screen &other) {
        height = other.height;
        width = other.width;
        sgamemode=other.sgamemode;
        return *this;
    }

    ~Screen() {};

    friend std::ostream &operator<<(std::ostream &os, const Screen &a) {
        os << "height: " << a.height << ", width: " << a.width << "\n";
        return os;
    }
    void print_hud(){
        cout<<hud;
    }
};


int main() {
    srand(time(NULL));
    Screen screen1(1080, 1920,{},{"classic"});
    Screen screen2=screen1;
    Screen screen3(screen1);
    cout<<screen2;
    cout<<screen3;
    Gamemode g1("classic");
    cout<<g1;
    Hud hud1;
    cout<<hud1;
    screen1.print_hud();
    hud1.insert_balance(100);
    hud1.insert_balance(50);
    hud1.play(10, g1);
    hud1.play(10, g1);
    Gamemode g2("book_of_ra");
    hud1.play(20, g2);
    hud1.double_the_win(10, "black");
    hud1.cashout();
    return 0;
}
