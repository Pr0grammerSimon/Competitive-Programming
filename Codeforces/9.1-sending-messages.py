ilosc_testow = int(input())

for i in range(ilosc_testow):
    num_messages,phone_charge,cons_on,cons_off = input().split()
    messages = input().split()
    num_messages,phone_charge,cons_on,cons_off = int(num_messages),int(phone_charge),int(cons_on),int(cons_off)


    mozna = True
    for e,message in enumerate(messages):
        #print(message, phone_charge)
        if e == 0: time = int(message)
        else: time = int(message) - int(messages[e-1])

        if time*cons_on > cons_off:
            phone_charge -= cons_off
        else:
            phone_charge -= cons_on*time
        if phone_charge < 1: 
            mozna = False
            break

    if mozna:
        print('YES')
    else:
        print('NO')
