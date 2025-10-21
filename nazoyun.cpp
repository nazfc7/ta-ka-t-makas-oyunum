#include <iostream>
#include <cstdlib>   // rand, srand
#include <ctime>     // time
#include <string>
using namespace std;
string moveName(int m) {
    if (m == 1) return "Tas";
    if (m == 2) return "Kagit";
    if (m == 3) return "Makas";
    return "Bilinmiyor";
}

// 0 = berabere, 1 = oyuncu kazandi, -1 = bilgisayar kazandi
int decideWinner(int player, int cpu) {
    if (player == cpu) return 0;
    // Tas(1) Kagit(2) Makas(3)
    if ((player == 1 && cpu == 3) ||
        (player == 2 && cpu == 1) ||
        (player == 3 && cpu == 2)) {
        return 1;
    }
    return -1;
}

int main() {
    srand((unsigned)time(nullptr));

    cout << "==== TAS - KAGIT - MAKAS ====\n";

    int playerScore = 0, cpuScore = 0;
    char playAgain = 'e';

    do {
        int rounds = 999;
        playerScore = 0;
        cpuScore = 0;

        cout << "\nKac tur oynamak istersin? (en fazla 999 tur oynayabilirsin!): ";
        if (!(cin >> rounds) || rounds <= 0) {
            cout << "Gecersiz tur sayisi, varsayilan 3 alindi.\n";
            rounds = 3;
            cin.clear();
            cin.ignore(10000, '\n');
        }

        for (int r = 1; r <= rounds; ++r) {
            cout << "\nTur " << r << " - Secimini yap: (1) Tas  (2) Kagit  (3) Makas\n";
            int player;
            cout << "Sen: ";
            while (!(cin >> player) || player < 1 || player > 3) {
                cout << "Hatali giris. 1, 2 veya 3 gir: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }

            int cpu = (rand() % 3) + 1;
            cout << "Bilgisayar: " << moveName(cpu)
                 << " - Sen: " << moveName(player) << "\n";

            int result = decideWinner(player, cpu);
            if (result == 0) {
                cout << "Berabere!\n";
            } else if (result == 1) {
                cout << "Bu turu sen kazandin!\n";
                ++playerScore;
            } else {
                cout << "Bu turu bilgisayar kazandi.\n";
                ++cpuScore;
            }

            cout << "Skor: Sen " << playerScore
                 << " - " << cpuScore << " Bilgisayar\n";
        }

        cout << "\n==== OYUN BITTI ====\n";
        if (playerScore > cpuScore)
            cout << "Tebrikler! Oyunu kazandin.\n";
        else if (playerScore < cpuScore)
            cout << "Bilgisayar kazandi.\n";
        else
            cout << "Oyun berabere bitti.\n";

        cout << "Tekrar oynamak ister misin? (e/h): ";
        cin >> playAgain;
        if (playAgain == 'E') playAgain = 'e';
        if (playAgain == 'H') playAgain = 'h';
    } while (playAgain == 'e');

    cout << "Oyunu oynadigin icin tesekkurler! Gorusuruz.\n";
    return 0;
}
