# Trabajo Práctico - Procesamiento de registros académicos
# Lenguaje: Python


#Calculo para saber si esta aplazado o no
def calcular_estado(puntaje):
    if puntaje >= 60:
        return "Aprobado"
    else:
        return "Reprobado"

#Confirmar puntaje correcto
def validar_puntaje(puntaje):
    return 0 <= puntaje <= 100

#Listado de estudiantes completo
def mostrar_estudiantes(estudiantes):
    if len(estudiantes) == 0:
        print("Error: la lista de estudiantes está vacía.")
        return

    print("\nLISTA DE ESTUDIANTES")
    print("-" * 70)

    for estudiante in estudiantes:
        print(
            "Código:", estudiante["codigo"],
            "| Nombre:", estudiante["nombre"],
            "| Carrera:", estudiante["carrera"],
            "| Puntaje:", estudiante["puntaje"],
            "| Estado:", estudiante["estado"]
        )

#Calculo del promedio general de los estudiantes
def calcular_promedio(estudiantes):
    if len(estudiantes) == 0:
        print("Error: no se puede calcular el promedio de una lista vacía.")
        return 0

    suma = 0

    for estudiante in estudiantes:
        suma += estudiante["puntaje"]

    return suma / len(estudiantes)


#Cuantos estan aplazados y cuantos aprobados
def contar_estados(estudiantes):
    aprobados = 0
    reprobados = 0

    for estudiante in estudiantes:
        if estudiante["estado"] == "Aprobado":
            aprobados += 1
        else:
            reprobados += 1

    return aprobados, reprobados

#Buscar estudiante especifico
def buscar_por_codigo(estudiantes, codigo):
    for estudiante in estudiantes:
        if estudiante["codigo"] == codigo:
            return estudiante

    return None

#Top de los estudiantes
def ordenar_por_puntaje(estudiantes):
    # Ordenamiento burbuja manual de mayor a menor
    n = len(estudiantes)

    for i in range(n - 1):
        for j in range(n - i - 1):
            if estudiantes[j]["puntaje"] < estudiantes[j + 1]["puntaje"]:
                aux = estudiantes[j]
                estudiantes[j] = estudiantes[j + 1]
                estudiantes[j + 1] = aux

#Mejor estudiante 
def obtener_mayor_puntaje(estudiantes):
    if len(estudiantes) == 0:
        return None

    mayor = estudiantes[0]

    for estudiante in estudiantes:
        if estudiante["puntaje"] > mayor["puntaje"]:
            mayor = estudiante

    return mayor

#Peor estudiante
def obtener_menor_puntaje(estudiantes):
    if len(estudiantes) == 0:
        return None

    menor = estudiantes[0]

    for estudiante in estudiantes:
        if estudiante["puntaje"] < menor["puntaje"]:
            menor = estudiante

    return menor

#Imprimir un estudiante específico
def imprimir_estudiante(estudiante):
    if estudiante is None:
        print("No se encontró el estudiante.")
    else:
        print(
            "Código:", estudiante["codigo"],
            "| Nombre:", estudiante["nombre"],
            "| Carrera:", estudiante["carrera"],
            "| Puntaje:", estudiante["puntaje"],
            "| Estado:", estudiante["estado"]
        )


# Programa principal

estudiantes = [
    {"codigo": "E001", "nombre": "Ana López", "carrera": "Informática", "puntaje": 85},
    {"codigo": "E002", "nombre": "Carlos Gómez", "carrera": "Informática", "puntaje": 58},
    {"codigo": "E003", "nombre": "María Torres", "carrera": "Electrónica", "puntaje": 92},
    {"codigo": "E004", "nombre": "José Martínez", "carrera": "Informática", "puntaje": 47},
    {"codigo": "E005", "nombre": "Lucía Fernández", "carrera": "Civil", "puntaje": 76},
    {"codigo": "E006", "nombre": "Pedro González", "carrera": "Electrónica", "puntaje": 63},
    {"codigo": "E007", "nombre": "Sofía Benítez", "carrera": "Informática", "puntaje": 99},
    {"codigo": "E008", "nombre": "Miguel Ruiz", "carrera": "Civil", "puntaje": 34},
    {"codigo": "E009", "nombre": "Laura Cáceres", "carrera": "Informática", "puntaje": 68},
    {"codigo": "E010", "nombre": "Diego Pereira", "carrera": "Electrónica", "puntaje": 55},
    {"codigo": "E011", "nombre": "Valeria Acosta", "carrera": "Civil", "puntaje": 81},
    {"codigo": "E012", "nombre": "Fernando Rojas", "carrera": "Informática", "puntaje": 40},
    {"codigo": "E013", "nombre": "Camila Duarte", "carrera": "Electrónica", "puntaje": 73},
    {"codigo": "E014", "nombre": "Rodrigo Sosa", "carrera": "Civil", "puntaje": 61},
    {"codigo": "E015", "nombre": "Elena Franco", "carrera": "Informática", "puntaje": 89}
]

    # Calcular automáticamente el estado y validar puntajes
for estudiante in estudiantes:
        if validar_puntaje(estudiante["puntaje"]):
            estudiante["estado"] = calcular_estado(estudiante["puntaje"])
        else:
            estudiante["estado"] = "Puntaje inválido"

while (True):
    opcion = input("Seleccione una opción: "
                   "1. Mostrar estudiantes\n"
                   "2. Calcular promedio\n"
                   "3. Contar quien paso y quien no\n"
                   "4. Buscar por código\n"
                   "5. Ordenar por puntaje\n"
                   "6. Obtener mayor puntaje\n"
                   "7. Obtener menor puntaje\n"
                   "8. Validar puntaje\n"
                   "9. Salir\n"
                   "Opción: ")

    if opcion == "1":
        mostrar_estudiantes(estudiantes)
        a=input("\nPresione Enter para continuar...")
        if(a):
            pass

    elif opcion == "2":
        promedio = calcular_promedio(estudiantes)
        print("\nPromedio general:", round(promedio, 2))
        a=input("\nPresione Enter para continuar...")
        if(a):
            pass

    elif opcion == "3":
        aprobados, reprobados = contar_estados(estudiantes)
        print("Cantidad de aprobados:", aprobados)
        print("Cantidad de reprobados:", reprobados)
        a=input("\nPresione Enter para continuar...")
        if(a):
            pass

    elif opcion == "4":
        print("\nBÚSQUEDA DE ESTUDIANTE POR CÓDIGO")
        codigo_buscado = "E007"
        resultado = buscar_por_codigo(estudiantes, codigo_buscado)
        print("Estudiante encontrado:")
        imprimir_estudiante(resultado)
        a=input("\nPresione Enter para continuar...")
        if(a):
            pass


    elif opcion == "5":
        print("\nESTUDIANTES ORDENADOS POR PUNTAJE DE MAYOR A MENOR")
        ordenar_por_puntaje(estudiantes)
        mostrar_estudiantes(estudiantes)
        a=input("\nPresione Enter para continuar...")
        if(a):
            pass



    elif opcion == "6":
        print("\nESTUDIANTE CON MAYOR PUNTAJE")
        mayor = obtener_mayor_puntaje(estudiantes)
        imprimir_estudiante(mayor)
        a=input("\nPresione Enter para continuar...")
        if(a):
            pass


    elif opcion == "7":
        print("\nESTUDIANTE CON MENOR PUNTAJE")
        menor = obtener_menor_puntaje(estudiantes)
        imprimir_estudiante(menor)
        a=input("\nPresione Enter para continuar...")
        if(a):
            pass

    elif opcion == "8":
        print("\nVALIDACIÓN DE PUNTAJE FUERA DE RANGO")
        puntaje_prueba = 120
        if validar_puntaje(puntaje_prueba):
            print("El puntaje", puntaje_prueba, "es válido.")
        else:
            print("Error: el puntaje", puntaje_prueba, "está fuera del rango permitido.")
        a=input("\nPresione Enter para continuar...")
        if(a):
            pass

    elif opcion == "9":
        print("Saliendo del programa...")
        break