import datetime

rok = int(input())

if rok==2030: print("niedziela")
elif rok<2010:print("Tak dawno to dinozaury chodzily po ziemi!")
elif rok>2030: print("To zbyt daleka przyszlosc!")
else:
    day = datetime.datetime(rok,6,1).weekday()
    if day==0: print("poniedzialek")
    elif day==1: print("wtorek")
    elif day==2: print("sroda")
    elif day==3: print("czwartek")
    elif day==4: print("piatek")
    elif day==5: print("sobota")
    else: print("niedziela")