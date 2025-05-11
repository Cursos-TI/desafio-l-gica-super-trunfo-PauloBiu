Carta:
    def __init__(self, estado, codigo, cidade, populacao, area, pib, pontos_turisticos):
        self.estado = estado
        self.codigo = codigo
        self.cidade = cidade
        self.populacao = populacao
        self.area = area
        self.pib = pib
        self.pontos_turisticos = pontos_turisticos
        self.densidade_populacional = populacao / area
        self.pib_per_capita = pib / populacao

    def __str__(self):
        return f"{self.cidade} ({self.estado} - {self.codigo})\n" \
               f"População: {self.populacao}\n" \
               f"Área: {self.area} km²\n" \
               f"PIB: R${self.pib}\n" \
               f"Pontos Turísticos: {self.pontos_turisticos}\n" \
               f"Densidade Populacional: {self.densidade_populacional:.2f} hab/km²\n" \
               f"PIB per Capita: R${self.pib_per_capita:.2f}"

def comparar_cartas(carta1, carta2, atributo):
    if atributo == "densidade_populacional":
        if carta1.densidade_populacional < carta2.densidade_populacional:
            return carta1
        elif carta1.densidade_populacional > carta2.densidade_populacional:
            return carta2
        else:
            return None
    else:
        if getattr(carta1, atributo) > getattr(carta2, atributo):
            return carta1
        elif getattr(carta1, atributo) < getattr(carta2, atributo):
            return carta2
        else:
            return None

def main():
    print("Bem-vindo ao Super Trunfo - Países!")
    print("Cadastro de Cartas")

    estado = input("Digite o estado da cidade: ")
    codigo = input("Digite o código da carta (ex: A01): ")
    cidade = input("Digite o nome da cidade: ")
    populacao = int(input("Digite a população da cidade: "))
    area = float(input("Digite a área da cidade (em km²): "))
    pib = float(input("Digite o PIB da cidade (em R$): "))
    pontos_turisticos = int(input("Digite o número de pontos turísticos da cidade: "))

    carta = Carta(estado, codigo, cidade, populacao, area, pib, pontos_turisticos)

    print("\nCarta cadastrada com sucesso!")
    print(carta)

    print("\nEscolha o atributo para comparação:")
    print("1. População")
    print("2. Área")
    print("3. PIB")
    print("4. Pontos Turísticos")
    print("5. Densidade Populacional")
    print("6. PIB per Capita")

    opcao = int(input("Digite o número correspondente ao atributo: "))

    atributos = ["populacao", "area", "pib", "pontos_turisticos", "densidade_populacional", "pib_per_capita"]
    atributo = atributos[opcao - 1]

    print("\nCadastro da segunda carta")

    estado2 = input("Digite o estado da cidade: ")
    codigo2 = input("Digite o código da carta (ex: A01): ")
    cidade2 = input("Digite o nome da cidade: ")
    populacao2 = int(input("Digite a população da cidade: "))
    area2 = float(input("Digite a área da cidade (em km²): "))
    pib2 = float(input("Digite o PIB da cidade (em R$): "))
    pontos_turisticos2 = int(input("Digite o número de pontos turísticos da cidade: "))

    carta2 = Carta(estado2, codigo2, cidade2, populacao2, area2, pib2, pontos_turisticos2)

    print("\nCarta cadastrada com sucesso!")
    print(carta2)

    vencedor = comparar_cartas(carta, carta2, atributo)

    if vencedor:
        print(f"\nA carta vencedora é: {vencedor.cidade}")
    else:
        print("\nHouve um empate!")

if __name__ == "__main__":
    main()