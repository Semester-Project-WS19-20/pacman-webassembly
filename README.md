## Änderungen die an Pacman vorgenommen wurden:
1. Doppelte Einbindung von SDL Komponenten entfernt: In `SoundManager.h` wurde `<SDL2/SDL.h>` und `<SDL/SDL_mixer.h>` eingebunden. Statdessen wird jetzt der `<SDL2/SDL_mixer.h>` eingebunden. In utils.h wurde `<SDL/SDL_ttf.h>` durch `<SDL2/SDL_ttf.h>` ersetzt.
2. Modifikation des Makefile.wasm, hinzufügen von in neueren Versionen neutigen Parametern.
3. Entfernen von `#ifdef _EMSCRIPTEN_` Konstrukten da ich mir nach Recherche nicht sicher war ob diese noch so unterstützt werden -> hat wahrscheinlich nichts gebracht.
4. Hinzufügen von Konsolen ausgaben zur Untersuchung des Programmflusses
## Aktueller Stand:
Pacman lässt sich jetzt mit hilfe des Makefiles builden und kann auch im Browser gestartet werden. Sobald im anfänglichen Menü 'Play' ausgewählt wird vermeldet der Browser `Uncaught SimulateInfiniteLoop` und das Spiel kann nicht gespielt werden.
