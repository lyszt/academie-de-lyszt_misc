#include <bits/stdc++.h>
using namespace std;

struct triple
{
    int ouro = 0;
    int prata = 0;
    int bronze = 0;
};

class Pais
{
public:
    string nome;
    triple prizes;

    Pais(string nome)
    {
        this->nome = nome;
    }
};

class Competicao
{
public:
    string descricao;
    string ouro;
    string prata;
    string bronze;
    unordered_map<string, Pais *> countries;

    Competicao(string descricao, string ouro, string prata, string bronze)
    {
        this->descricao = descricao;
        this->ouro = ouro;
        this->prata = prata;
        this->bronze = bronze;
    }
};

bool comparator(Pais *a, Pais *b)
{
    if (a->prizes.ouro == b->prizes.ouro && a->prizes.prata == b->prizes.prata && a->prizes.bronze == b->prizes.bronze)
    {
        return a->nome < b->nome;
    }
    else if (a->prizes.ouro == b->prizes.ouro && a->prizes.prata == b->prizes.prata)
    {
        return a->prizes.bronze > b->prizes.bronze;
    }
    else if (a->prizes.ouro == b->prizes.ouro)
    {
        return a->prizes.prata > b->prizes.prata;
    }
    
    return a->prizes.ouro > b->prizes.ouro;
}

void trim(string &str){
    while(!str.empty() && str.front() == '\r'){
        str.erase(str.begin());
    }
    while(!str.empty() && str.back() == '\r'){
        str.pop_back();
    }
}

int main()
{
    // AAAAAAAAAAAAAA ADICIONARAM UMA RUSSIA COM ESPAÇO AAAAAAAAAAAAAAAAAAAAAAAAA
    // * presentation error *
    string descricao;
    unordered_map<string, int> prizes;
    vector<Pais *> countries_ordered;
    Competicao *competition = new Competicao("", "", "", "");
    while (getline(cin, descricao))
    {
        string ouro, prata, bronze;
        getline(cin, ouro);
        getline(cin, prata);
        getline(cin, bronze);
        trim(ouro);
        trim(prata);
        trim(bronze);
        competition->ouro = ouro;
        competition->prata = prata;
        competition->bronze = bronze;
        Pais *first = new Pais(ouro);
        Pais *second = new Pais(prata);
        Pais *third = new Pais(bronze);

        if (competition->countries.count(ouro) == 0)
        {
            competition->countries[ouro] = first;
            competition->countries[ouro]->prizes.ouro++;
        }
        else
        {
            competition->countries[ouro]->prizes.ouro++;
        }
        if (competition->countries.count(prata) == 0)
        {
            competition->countries[prata] = second;
            competition->countries[prata]->prizes.prata++;
        }
        else
        {
            competition->countries[prata]->prizes.prata++;
        }
        if (competition->countries.count(bronze) == 0)
        {
            competition->countries[bronze] = third;
            competition->countries[bronze]->prizes.bronze++;
        }
        else
        {
            competition->countries[bronze]->prizes.bronze++;
        }
    }
    cout << "Quadro de Medalhas\n";
    for (auto country : competition->countries)
    {
        countries_ordered.push_back(country.second);
    }
    std::sort(countries_ordered.begin(), countries_ordered.end(), comparator);
    for (auto country : countries_ordered)
    {
        cout << country->nome << " " << country->prizes.ouro
             << " " << country->prizes.prata << " " << country->prizes.bronze << "\n";
    }
    return 0;
}
