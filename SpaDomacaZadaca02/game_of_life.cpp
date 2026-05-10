#include "game_of_life.h"
#include <ctime>

//
bool game_of_life::slucajna_vrijednost()
{
    return (rand() % 100) < 25;
}
//

//
bool game_of_life::celija_zauzeta(int tren_redak, int tren_stupac)
{
    if (tren_redak < 0 or tren_redak >= REDAKA or tren_stupac < 0 or tren_stupac >= STUPACA) {
        return false;
    }

    return _generacija[tren_redak][tren_stupac];
}
//

//
game_of_life::game_of_life()
{
    srand(time(nullptr));

    for (int tren_redak = 0; tren_redak < REDAKA; tren_redak++)
    {
        for (int tren_stupac = 0; tren_stupac < STUPACA; tren_stupac++)
        {
            _generacija[tren_redak][tren_stupac] = slucajna_vrijednost();
        }
    }
}
//

//
void game_of_life::sljedeca_generacija()
{
    for (int tren_redak = 0; tren_redak < REDAKA; tren_redak++)
    {
        for (int tren_stupac = 0; tren_stupac < STUPACA; tren_stupac++)
        {
            int zivih_susjednih = 0;

            for (int tren_pomak_redak = -1; tren_pomak_redak <= 1; tren_pomak_redak++)
            {
                for (int tren_pomak_stupaca = -1; tren_pomak_stupaca <= 1; tren_pomak_stupaca++)
                {
                    if (tren_pomak_redak == 0 && tren_pomak_stupaca == 0)
                    {
                        continue;
                    }

                    if (celija_zauzeta(tren_redak + tren_pomak_redak, tren_stupac + tren_pomak_stupaca))
                    {
                        zivih_susjednih++;
                    }
                }
            }

            bool trenutno_ziva = _generacija[tren_redak][tren_stupac];

            if (trenutno_ziva)
            {
                _sljedeca_generacija[tren_redak][tren_stupac] = (zivih_susjednih == 2 || zivih_susjednih == 3);
            }

            else
            {
                _sljedeca_generacija[tren_redak][tren_stupac] = (zivih_susjednih == 3);
            }
        }
    }

    for (int tren_redak = 0; tren_redak < REDAKA; tren_redak++)
    {
        for (int tren_stupac = 0; tren_stupac < STUPACA; tren_stupac++)
        {
            _generacija[tren_redak][tren_stupac] = _sljedeca_generacija[tren_redak][tren_stupac];
        }
    }
}
//

//
void game_of_life::iscrtaj()
{
    for (int tren_redak = 0; tren_redak < REDAKA; tren_redak++)
    {
        for (int tren_stupac = 0; tren_stupac < STUPACA; tren_stupac++)
        {
            if (_generacija[tren_redak][tren_stupac])
            {
                cout << "*";
            }

            else
            {
                cout << ".";
            }
        }
        cout << endl;
    }
}
//