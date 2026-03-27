#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

void setup();
void disegna_campo(int y, int x);
void disegna_racchetta(int riga_partenza, int colonna, int lunghezza);
void gestisci_input(int key, int *racket_y);

// mvvline()

int main() {

    setup();

    // --- gioco
    // int h, w, pos_verticale, half_h;

    // getmaxyx(stdscr, h, w);
    // half_h= h/2;

    // mvhline(riga dove disegnare, colonna da cui parte, carattere da scrivere, quante volte ripeterlo)
    // mvvline(riga da cui parte, colonna in cui disegnare, carattere da scrivere, quante volte scendere)

    // 0
    // 0
    // 0
    // 0
    // 0
    // 0
    // 0
    // 0
    // 0
    // 0

    int y, x, half_y,
        racket_y, bot_racket_y;
    int racket_length;

    getmaxyx(stdscr, y, x);

    if(y < 24 || x < 80) {
        endwin();
        printf("Muchachito!!!!\nTerminale troppo piccolo! Minimo 80x24.\n");
        return 1;
    }
    racket_length = y/5;
    racket_y = bot_racket_y = half_y= y/2;
    
    while(1) {

        clear();

        disegna_campo(y, x);

        disegna_racchetta(racket_y, 2, racket_length);
        disegna_racchetta(bot_racket_y, x - 3, racket_length);

        refresh();
        

        int key = getch(); // getch() legge un tasto premuto
        if(key == 'q')              break;
        gestisci_input(key, &racket_y);

        
    }

    // while(1) {
    //     clear(); // pulisce tutto lo schermo
    //     mvaddch(y, x, 'O'); // stampa un singolo carattere
    //     refresh(); // aggiorna schermo

    //     int tasto = getch(); // getch() legge un tasto premuto
    //     if(tasto == KEY_UP)         y--;
    //     if(tasto == KEY_DOWN)       y++;
    //     if(tasto == KEY_LEFT)       x--;
    //     if(tasto == KEY_RIGHT)      x++;
    //     if(tasto == 'q')              break;

    // }

    // getch();
    // refresh();

    endwin();             // ripristina il terminale normale

    return 0;
}

void setup() {
    initscr();            // inizializza ncurses
    cbreak();             // input carattere per carattere (senza Invio)
    noecho();             // non mostrare i tasti premuti
    keypad(stdscr, TRUE); // abilita frecce direzionali
    curs_set(0);          // nascondi il cursore
}

void disegna_campo(int y, int x) {
    // orizzontale
    mvhline(0, 0, '-', x);
    mvhline(y - 1, 0, '-', x);

    // verticale
    mvvline(0, 0, '(', y);
    mvvline(0, x - 1, ')', y);
}

void disegna_racchetta(int riga_partenza, int colonna, int lunghezza) {
    mvvline(riga_partenza - lunghezza, colonna, '|', 2*lunghezza);
}

void gestisci_input(int key, int *racket_y) {

    if(lunghezza +)

    if(key == KEY_UP)       (*racket_y)--;
    if(key == KEY_DOWN)     (*racket_y)++;
}