ilosc_fil = int(input())
dict_ = {}
for i in range(ilosc_fil):
    name = input()
    cena = int(input())
    dostepnosc = int(input())
    kolor = input()
    dict_[name] = [cena,dostepnosc,kolor]

ilosc_zapytan = int(input())
for i in range(ilosc_zapytan):
    nazwa = input()
    if nazwa in dict_:
        informacje = dict_[nazwa]
        if informacje[1]:
            print("Nazwa:",nazwa)
            print("Kolor:", informacje[2])
            print("Cena:", informacje[0])
        else:
            print("Produkt ktorego szukasz jest niedostepny")
    else:
        print("Produkt ktorego szukasz nie istnieje")
        