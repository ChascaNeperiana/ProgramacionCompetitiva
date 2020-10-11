#include "primo.h"
#include <iostream>

// Main
//	int primo(int posicion)

int busca(int n) {
	int mios[n];
	int res[n];
	bool esPrimo[n+5];
	for (int i=0; i<=n; i++) {
        esPrimo[i] = true;
	}
	int ult;
	int p = 0;
	for (int voy = 2; voy*voy<=n; voy++) {
        if (esPrimo[voy]) {
            mios[p] = voy;
            res[p] = -1;
            p++;
            ult = voy;
            for (int i = 2*voy; i<=n; i+=voy) {
                esPrimo[i] = false;
            }
        }
	}
	ult++;
	while (ult<=n) {
        if (esPrimo[ult]) {
            mios[p] = ult;
            p++;
        }
        ult++;
	}
	int ini = 0, fin = p-1;
	while (ini != fin) {
        int mitad = (ini+fin)/2;
        res[mitad] = primo(mitad);
        if (res[mitad] == mios[mitad]) {
            ini = mitad + 1;
        }
        else {
            fin = mitad;
        }
	}
	int dos = 2;
    if (n == dos) {
        return dos;
    }
	if (res[ini] == -1) {
        res[ini] = primo(ini);
	}
	if (mios[ini] == res[ini]) {
        return mios[p-1];
	}
	else {
        return mios[ini];
	}
	return 0;
}
