#include <bits/stdc++.h>
using namespace std;

int n, k, turn;
int cards[14][14] = {0};
int winner = -1;

bool isWinner(int id) {
    int cont = 0, soma =0;
    if (cards[id][0] != 0) return false;

    for (int i=1;i<14;++i) {
        if (cards[id][i] != 0){
            cont++;
            if (cont >= 2) return false;
        }

        soma += cards[id][i];
    }

    if (soma == 4) return true;

    return false;
}

int chooseCard(int id) {
    int menor = 1000, id_menor = -1;
    for (int i=1;i<14;++i) {
        if (cards[id][i] < menor && cards[id][i] != 0){
            menor = cards[id][i];
            id_menor = i;
        }
    }

    return id_menor;
}

int getCardNumber(char c) {
    if (c == 'A') return 1;
    else if (c == '2') return 2;
    else if (c == '3') return 3;
    else if (c == '4') return 4;
    else if (c == '5') return 5;
    else if (c == '6') return 6;
    else if (c == '7') return 7;
    else if (c == '8') return 8;
    else if (c == '9') return 9;
    else if (c == 'D') return 10;
    else if (c == 'Q') return 11;
    else if (c == 'J') return 12;
    else if (c == 'K') return 13;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    string mao;

    cards[k-1][0] = 2;
    turn = k-1;

    for (int i=0;i<n;i++){
        cin >> mao;
        for (int j=0;j<mao.size();++j){
            int card = getCardNumber(mao[j]);
            cards[i][card]++;
        }

        if (isWinner(i) && winner == -1) {
            winner = i+1;
        }
    }
    
    // já saiu com as cartas para vencer
    if (winner != -1) {
        cout << winner << endl;
        return 0;
    }

    while (true) {
        int p_turn = (turn + 1) % n;
        // Passar o coringa!
        if (cards[turn][0] == 1) {
            cards[turn][0]--;
            cards[p_turn][0] = 2;
        } else {
            // se tiver o coringa, mas n pode passar
            if (cards[turn][0] == 2)
                cards[turn][0] = 1;

            // passar menor carta
            int c_id = chooseCard(turn);
            cards[turn][c_id]--;
            cards[p_turn][c_id]++;
        }

        // checar se o jogador da turn ou o próximo estão com 4 cartas iguais
        if (isWinner(turn)) break;
        else if (isWinner(p_turn)){
            turn = p_turn;
            break;
        }

        turn = p_turn;
    }

    cout << (turn + 1) << endl;
    return 0;
}
