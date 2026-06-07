# Trabajo Práctico - Procesamiento de registros académicos
# Lenguaje: Ruby

# Calculo para saber si esta aplazado o no
def calcular_estado(puntaje)
  if puntaje >= 60
    "Aprobado"
  else
    "Reprobado"
  end
end

# Confirmar puntaje correcto
def validar_puntaje(puntaje)
  puntaje >= 0 && puntaje <= 100
end

# Listado de estudiantes completo
def mostrar_estudiantes(estudiantes)
  if estudiantes.length == 0
    puts "Error: la lista de estudiantes está vacía."
    return
  end

  puts "\nLISTA DE ESTUDIANTES"
  puts "-" * 70

  estudiantes.each do |estudiante|
    imprimir_estudiante(estudiante)
  end
end

# Calculo del promedio general de los estudiantes
def calcular_promedio(estudiantes)
  if estudiantes.length == 0
    puts "Error: no se puede calcular el promedio de una lista vacía."
    return 0
  end

  suma = 0

  estudiantes.each do |estudiante|
    suma += estudiante[:puntaje]
  end

  suma.to_f / estudiantes.length
end

# Cuantos estan aplazados y cuantos aprobados
def contar_estados(estudiantes)
  aprobados = 0
  reprobados = 0

  estudiantes.each do |estudiante|
    if estudiante[:estado] == "Aprobado"
      aprobados += 1
    else
      reprobados += 1
    end
  end

  [aprobados, reprobados]
end

# Buscar estudiante especifico
def buscar_por_codigo(estudiantes, codigo)
  estudiantes.each do |estudiante|
    if estudiante[:codigo] == codigo
      return estudiante
    end
  end

  nil
end

# Top de los estudiantes
def ordenar_por_puntaje(estudiantes)
  # Ordenamiento burbuja manual de mayor a menor
  n = estudiantes.length

  for i in 0...(n - 1)
    for j in 0...(n - i - 1)
      if estudiantes[j][:puntaje] < estudiantes[j + 1][:puntaje]
        aux = estudiantes[j]
        estudiantes[j] = estudiantes[j + 1]
        estudiantes[j + 1] = aux
      end
    end
  end
end

# Mejor estudiante
def obtener_mayor_puntaje(estudiantes)
  if estudiantes.length == 0
    return nil
  end

  mayor = estudiantes[0]

  estudiantes.each do |estudiante|
    if estudiante[:puntaje] > mayor[:puntaje]
      mayor = estudiante
    end
  end

  mayor
end

# Peor estudiante
def obtener_menor_puntaje(estudiantes)
  if estudiantes.length == 0
    return nil
  end

  menor = estudiantes[0]

  estudiantes.each do |estudiante|
    if estudiante[:puntaje] < menor[:puntaje]
      menor = estudiante
    end
  end

  menor
end

# Imprimir un estudiante específico
def imprimir_estudiante(estudiante)
  if estudiante.nil?
    puts "No se encontró el estudiante."
  else
    puts "Código: #{estudiante[:codigo]} | Nombre: #{estudiante[:nombre]} | Carrera: #{estudiante[:carrera]} | Puntaje: #{estudiante[:puntaje]} | Estado: #{estudiante[:estado]}"
  end
end

def pausar
  print "\nPresione Enter para continuar..."
  gets
end

def mostrar_menu
  puts "\nSeleccione una opción:"
  puts "1. Mostrar estudiantes"
  puts "2. Calcular promedio"
  puts "3. Contar quien paso y quien no"
  puts "4. Buscar por código"
  puts "5. Ordenar por puntaje"
  puts "6. Obtener mayor puntaje"
  puts "7. Obtener menor puntaje"
  puts "8. Validar puntaje"
  puts "9. Salir"
  print "Opción: "
end

# Programa principal

estudiantes = [
  { codigo: "E001", nombre: "Ana López", carrera: "Informática", puntaje: 85 },
  { codigo: "E002", nombre: "Carlos Gómez", carrera: "Informática", puntaje: 58 },
  { codigo: "E003", nombre: "María Torres", carrera: "Electrónica", puntaje: 92 },
  { codigo: "E004", nombre: "José Martínez", carrera: "Informática", puntaje: 47 },
  { codigo: "E005", nombre: "Lucía Fernández", carrera: "Civil", puntaje: 76 },
  { codigo: "E006", nombre: "Pedro González", carrera: "Electrónica", puntaje: 63 },
  { codigo: "E007", nombre: "Sofía Benítez", carrera: "Informática", puntaje: 99 },
  { codigo: "E008", nombre: "Miguel Ruiz", carrera: "Civil", puntaje: 34 },
  { codigo: "E009", nombre: "Laura Cáceres", carrera: "Informática", puntaje: 68 },
  { codigo: "E010", nombre: "Diego Pereira", carrera: "Electrónica", puntaje: 55 },
  { codigo: "E011", nombre: "Valeria Acosta", carrera: "Civil", puntaje: 81 },
  { codigo: "E012", nombre: "Fernando Rojas", carrera: "Informática", puntaje: 40 },
  { codigo: "E013", nombre: "Camila Duarte", carrera: "Electrónica", puntaje: 73 },
  { codigo: "E014", nombre: "Rodrigo Sosa", carrera: "Civil", puntaje: 61 },
  { codigo: "E015", nombre: "Elena Franco", carrera: "Informática", puntaje: 89 }
]

# Calcular automáticamente el estado y validar puntajes
estudiantes.each do |estudiante|
  if validar_puntaje(estudiante[:puntaje])
    estudiante[:estado] = calcular_estado(estudiante[:puntaje])
  else
    estudiante[:estado] = "Puntaje inválido"
  end
end

salir = false

while !salir
  mostrar_menu
  opcion = gets.chomp

  if opcion == "1"
    mostrar_estudiantes(estudiantes)
    pausar

  elsif opcion == "2"
    promedio = calcular_promedio(estudiantes)
    puts "\nPromedio general: #{format('%.2f', promedio)}"
    pausar

  elsif opcion == "3"
    estados = contar_estados(estudiantes)
    puts "Cantidad de aprobados: #{estados[0]}"
    puts "Cantidad de reprobados: #{estados[1]}"
    pausar

  elsif opcion == "4"
    puts "\nBÚSQUEDA DE ESTUDIANTE POR CÓDIGO"
    print "Ingrese el código del estudiante: "
    codigo_buscado = gets.chomp

    resultado = buscar_por_codigo(estudiantes, codigo_buscado)

    if !resultado.nil?
      puts "Estudiante encontrado:"
      imprimir_estudiante(resultado)
    else
      puts "Error: no existe un estudiante con el código #{codigo_buscado}"
    end

    pausar

  elsif opcion == "5"
    puts "\nESTUDIANTES ORDENADOS POR PUNTAJE DE MAYOR A MENOR"
    ordenar_por_puntaje(estudiantes)
    mostrar_estudiantes(estudiantes)
    pausar

  elsif opcion == "6"
    puts "\nESTUDIANTE CON MAYOR PUNTAJE"
    mayor = obtener_mayor_puntaje(estudiantes)
    imprimir_estudiante(mayor)
    pausar

  elsif opcion == "7"
    puts "\nESTUDIANTE CON MENOR PUNTAJE"
    menor = obtener_menor_puntaje(estudiantes)
    imprimir_estudiante(menor)
    pausar

  elsif opcion == "8"
    puts "\nVALIDACIÓN DE PUNTAJE"
    print "Ingrese un puntaje para validar: "
    entrada = gets.chomp

    begin
      puntaje_prueba = Integer(entrada)

      if validar_puntaje(puntaje_prueba)
        puts "El puntaje #{puntaje_prueba} es válido."
      else
        puts "Error: el puntaje #{puntaje_prueba} está fuera del rango permitido."
      end

    rescue ArgumentError
      puts "Error: debe ingresar un número entero."
    end

    pausar

  elsif opcion == "9"
    puts "Saliendo del programa..."
    salir = true

  else
    puts "Opción inválida."
    pausar
  end
end