// Refer to problem - https://www.hackerrank.com/challenges/magic-spells/problem

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell {
private:
    string scrollName;
public:
    Spell() : scrollName("") { }
    Spell(string name) : scrollName(name) { }
    virtual ~Spell() { }
    string revealScrollName() 
    {
        return scrollName;
    }
};

class Fireball : public Spell 
{
private: int power;
public:
    Fireball(int power) : power(power) { }
    void revealFirepower() 
    {
        cout << "Fireball: " << power << endl;
    }
};

class Frostbite : public Spell 
{
private: int power;
public:
    Frostbite(int power) : power(power) { }
    void revealFrostpower() 
    {
        cout << "Frostbite: " << power << endl;
    }
};

class Thunderstorm : public Spell 
{
private: int power;
public:
    Thunderstorm(int power) : power(power) { }
    void revealThunderpower() 
    {
        cout << "Thunderstorm: " << power << endl;
    }
};

class Waterbolt : public Spell 
{
private: int power;
public:
    Waterbolt(int power) : power(power) { }
    void revealWaterpower() 
    {
        cout << "Waterbolt: " << power << endl;
    }
};

class SpellJournal 
{
public:
    static string journal;
    static string read() 
    {
        return journal;
    }
};
string SpellJournal::journal = "";

void counterspell(Spell* spell) 
{

    Fireball* fb = dynamic_cast<Fireball*>(spell);
    if (fb)
    {
        fb->revealFirepower();
        return;
    }

    Frostbite* fob = dynamic_cast<Frostbite*>(spell);
    if (fob)
    {
        fob->revealFrostpower();
        return;
    }

    Waterbolt* wb = dynamic_cast<Waterbolt *>(spell);
    if (wb)
    {
        wb->revealWaterpower();
        return;
    }

    Thunderstorm* ths = dynamic_cast<Thunderstorm*>(spell);
    if (ths)
    {
        ths->revealThunderpower();
        return;
    }

    string scrollName = spell->revealScrollName();
    string journal = SpellJournal::read();
    int numRow = scrollName.length();
    int numCol = journal.length();
    int** lenLcs = new int* [numRow + 1];
    for (int i = 0; i < numRow + 1; i++)
    {
        lenLcs[i] = new int[numCol + 1];
        for (int j = 0; j < numCol + 1; j++)
        {
            lenLcs[i][j] = 0;
        }
    }
    for (int i = 1; i < numRow + 1; i++)
    {
        for (int j = 1; j < numCol + 1; j++)
        {
            if (scrollName[i - 1] == journal[j - 1])
            {
                lenLcs[i][j] = lenLcs[i - 1][j - 1] + 1;
            }
            else 
            {
                lenLcs[i][j] = (lenLcs[i - 1][j] > lenLcs[i][j - 1]) ? lenLcs[i - 1][j] : lenLcs[i][j - 1];
            }
        }
    }

    cout << lenLcs[numRow][numCol] << endl;

    for (int i = 0; i < numRow; i++)
    {
        delete lenLcs[i];
    }
    delete lenLcs;
}

class Wizard 
{
public:
    Spell* cast() 
    {
        Spell* spell;
        string s; cin >> s;
        int power; cin >> power;
        if (s == "fire") 
        {
            spell = new Fireball(power);
        }
        else if (s == "frost") 
        {
            spell = new Frostbite(power);
        }
        else if (s == "water") 
        {
            spell = new Waterbolt(power);
        }
        else if (s == "thunder") 
        {
            spell = new Thunderstorm(power);
        }
        else 
        {
            spell = new Spell(s);
            cin >> SpellJournal::journal;
        }
        return spell;
    }
};

int main() 
{
    int T;
    cin >> T;
    Wizard Arawn;
    while (T--) 
    {
        Spell* spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}