#include <bits/stdc++.h>
using namespace std;


unordered_map<long long int, bool> memo;
bool isWinningState(long long int n) {
    if(n==0) return false;
    if(memo.count(n)) return memo[n];
    for(long long int i = 1; i <= n; i *= 2){
        if(!isWinningState(n-i)){
            return memo[n] = true;
        }
    }
    return memo[n] = false;
}

bool isPowerOf2(long long int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}

// cara doido resolveu fazer um jogo
class Player;

class GameState
{
public:
    long long int n;
    Player* turn;
    GameState(long long int n)
    {
        this->n = n;
        this->turn = nullptr;
    }
};

class Player
{
public:
    GameState* gameState;
    const char* name;
    bool canWin;
    Player(const char* name, GameState* game_state);
    bool getCanWin();
    long long int optimalChoice(long long int n);
    void play();
};

Player::Player(const char* name, GameState* game_state)
{
    this->name = name;
    this->gameState = game_state;
    this->canWin = false;
    if (game_state->n == 1 || game_state->n == 0)
    {
        this->canWin = true;
    }
}

bool Player::getCanWin()
{
    return this->canWin;
}

long long int Player::optimalChoice(long long int n)
{
    vector<long long int> numbers;
    if(n <= 0) {return n;}
    for (long long int i = 1; i <= n; i *= 2)
    {
        if (!isWinningState(n - i)) {
            return i;
        }
    }
    return 1;
}

void Player::play()
{
    this->gameState->turn = this;
    long long int choice;
    long long int n = gameState->n;
    if (isPowerOf2(n))
    {
        choice = n;
        this->canWin = true;
    }
    else
    {
        long long int current_n = n;
        do
        {
            choice = optimalChoice(current_n);
            if(n - choice <= 0) {
                this->canWin = true;
            }
            current_n -= 1;
        } while (current_n > 1 && (current_n - choice) - optimalChoice(current_n - choice) <= 0);
    }


    this->gameState->n -= choice;
}


void ganha() {
    cout << "GANHA" << "\n";
}

void perde() {
    cout << "PERDE" << "\n";
}

int main()
{
    long long int n;
    cin >> n;
    GameState state = GameState(n);
    Player a = Player("ada", &state);
    Player p = Player("professor", &state);
    if(a.getCanWin()){ganha(); return 0;}
    while (!a.getCanWin() && !p.getCanWin())
    {
        a.play();
        if(a.getCanWin()){break;}
        p.play();
    }
    if(state.turn->name == a.name) {
        ganha();
        return 0;
    }
    perde();
    return 0;
}