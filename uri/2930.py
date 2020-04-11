while True:
    try:
        a, b = [int(x) for x in input().split()]
        s1 = 'Muito bem! Apresenta antes do Natal!'
        s2 = 'Parece o trabalho do meu filho!'
        s3 = 'Fail! Entao eh nataaaaal!'
        s4 = 'TCC Apresentado!'
        s5 = 'Eu odeio a professora!'
        if a > b:
            print(s5)
        elif a <= b-3:
            print(s1)
        else:
            print(s2)
            print(s4) if a+2 < 24 else print(s3)

    except EOFError:
        break