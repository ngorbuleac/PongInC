# PongInC

Pong in C nel terminale usando ncurses, sviluppato su macOS.

## Stato attuale

- Due racchette disegnate nel terminale (giocatore a sinistra, bot a destra)
- La racchetta del giocatore si muove con le frecce su/giù
- Premi `q` per uscire

## Requisiti

- macOS con Xcode Command Line Tools
- ncurses (installabile con `brew install ncurses`)

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
| `↑` | Muovi racchetta su |
| `↓` | Muovi racchetta giù |
| `q` | Esci |

## Struttura del codice

- `setup()` — inizializza ncurses
- `disegna_racchetta(riga_partenza, colonna, lunghezza)` — disegna una racchetta verticale
- `gestisci_input(key, *racket_y)` — gestisce l'input del giocatore