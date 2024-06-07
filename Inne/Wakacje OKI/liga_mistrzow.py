imie,ilosc_goli,ilosc_meczy = input().split()
wynik = round(int(ilosc_goli)/int(ilosc_meczy),2)
if wynik % 1 == 0: wynik = int(wynik)
print(f"{imie} strzela srednio {wynik} gola na mecz.")