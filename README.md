# PongInC

Pong in C nel terminale usando ncurses, sviluppato su macOS.

## Stato attuale

- Campo da gioco con bordi disegnati nel terminale
- Due racchette (giocatore a sinistra, bot a destra)
- Dimensione racchetta proporzionale all'altezza del terminale
- La racchetta del giocatore si muove con le frecce su/giù oppure W/S
- Controllo dimensione minima del terminale all'avvio
- Premi `q` per uscire

## Requisiti

- macOS con Xcode Command Line Tools
- ncurses (installabile con `brew install ncurses`)
- Terminale di almeno 80x24

## Compilazione

```bash
gcc -g main.c -o main -I/opt/homebrew/opt/ncurses/include -L/opt/homebrew/opt/ncurses/lib -lncurses
```

## Esecuzione

```bash
./main
```

## Controlli

| Tasto | Azione |
|-------|--------|
| `↑` / `W` | Muovi racchetta su |
| `↓` / `S` | Muovi racchetta giù |
| `q` | Esci |

## Struttura del codice

- `setup()` — inizializza ncurses
- `disegna_campo(y, x)` — disegna i bordi del campo
- `disegna_racchetta(riga_partenza, colonna, lunghezza)` — disegna una racchetta verticale
- `gestisci_input(key, *racket_y)` — gestisce l'input del giocatore