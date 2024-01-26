import sys
tabulacja = '    '
ilosc_tabulacji = 0
ilosc_nowych = 0
#lista = []
wynik = []
linia = ' '
for linia in sys.stdin:
    for i in linia.split():
        for znaki in i.split('>'):
            mozna_pisac = True
            ilosc_tabulacji += ilosc_nowych
            ilosc_nowych = 0
            wiersz = ''
            for e,element in enumerate(znaki):
                if element == '<':
                    if znaki[e+1] != '/':
                        ilosc_nowych +=1
                        #lista.append([znaki,'oh',ilosc_tabulacji,ilosc_nowych])
                elif element == '/':
                    mozna_pisac = False
                    ilosc_nowych -= 1
                    #lista.append([znaki,'uwu',ilosc_tabulacji,ilosc_nowych])
                elif element == '"':
                    continue
                elif element == '=':
                    wiersz += ' = '
                elif mozna_pisac:
                    wiersz += element
            wynik.append(tabulacja * ilosc_tabulacji + wiersz)

for i in wynik:
    if len(i.strip()) != 0:
        if '=' not in i:
            print(i + ':')
        else:
            print(i)
#print(lista)