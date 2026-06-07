package Gabriel_Gonzalez_Lujan_Rios_TP_Lenguajes.Java;
import java.util.Scanner;

public class estudiantes {

    static class Estudiante {
        String codigo;
        String nombre;
        String carrera;
        int puntaje;
        String estado;

        Estudiante(String codigo, String nombre, String carrera, int puntaje) {
            this.codigo = codigo;
            this.nombre = nombre;
            this.carrera = carrera;
            this.puntaje = puntaje;
            this.estado = calcularEstado(puntaje);
        }
    }

    // Calculo para saber si está aplazado o no
    public static String calcularEstado(int puntaje) {
        if (puntaje >= 60) {
            return "Aprobado";
        } else {
            return "Reprobado";
        }
    }

    // Confirmar puntaje correcto
    public static boolean validarPuntaje(int puntaje) {
        return puntaje >= 0 && puntaje <= 100;
    }

    // Listado de estudiantes completo
    public static void mostrarEstudiantes(Estudiante[] estudiantes) {
        if (estudiantes.length == 0) {
            System.out.println("Error: la lista de estudiantes está vacía.");
            return;
        }

        System.out.println("\nLISTA DE ESTUDIANTES");
        System.out.println("----------------------------------------------------------------------");

        for (int i = 0; i < estudiantes.length; i++) {
            imprimirEstudiante(estudiantes[i]);
        }
    }

    // Calculo del promedio general de los estudiantes
    public static double calcularPromedio(Estudiante[] estudiantes) {
        if (estudiantes.length == 0) {
            System.out.println("Error: no se puede calcular el promedio de una lista vacía.");
            return 0;
        }

        int suma = 0;

        for (int i = 0; i < estudiantes.length; i++) {
            suma += estudiantes[i].puntaje;
        }

        return (double) suma / estudiantes.length;
    }

    // Cuantos están aplazados y cuantos aprobados
    public static int[] contarEstados(Estudiante[] estudiantes) {
        int aprobados = 0;
        int reprobados = 0;

        for (int i = 0; i < estudiantes.length; i++) {
            if (estudiantes[i].estado.equals("Aprobado")) {
                aprobados++;
            } else {
                reprobados++;
            }
        }

        return new int[]{aprobados, reprobados};
    }

    // Buscar estudiante específico
    public static Estudiante buscarPorCodigo(Estudiante[] estudiantes, String codigo) {
        for (int i = 0; i < estudiantes.length; i++) {
            if (estudiantes[i].codigo.equals(codigo)) {
                return estudiantes[i];
            }
        }

        return null;
    }

    // Top de los estudiantes
    public static void ordenarPorPuntaje(Estudiante[] estudiantes) {
        // Ordenamiento burbuja manual de mayor a menor
        int n = estudiantes.length;

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (estudiantes[j].puntaje < estudiantes[j + 1].puntaje) {
                    Estudiante aux = estudiantes[j];
                    estudiantes[j] = estudiantes[j + 1];
                    estudiantes[j + 1] = aux;
                }
            }
        }
    }

    // Mejor estudiante
    public static Estudiante obtenerMayorPuntaje(Estudiante[] estudiantes) {
        if (estudiantes.length == 0) {
            return null;
        }

        Estudiante mayor = estudiantes[0];

        for (int i = 0; i < estudiantes.length; i++) {
            if (estudiantes[i].puntaje > mayor.puntaje) {
                mayor = estudiantes[i];
            }
        }

        return mayor;
    }

    // Peor estudiante
    public static Estudiante obtenerMenorPuntaje(Estudiante[] estudiantes) {
        if (estudiantes.length == 0) {
            return null;
        }

        Estudiante menor = estudiantes[0];

        for (int i = 0; i < estudiantes.length; i++) {
            if (estudiantes[i].puntaje < menor.puntaje) {
                menor = estudiantes[i];
            }
        }

        return menor;
    }

    // Imprimir un estudiante específico
    public static void imprimirEstudiante(Estudiante estudiante) {
        if (estudiante == null) {
            System.out.println("No se encontró el estudiante.");
        } else {
            System.out.println(
                "Código: " + estudiante.codigo +
                " | Nombre: " + estudiante.nombre +
                " | Carrera: " + estudiante.carrera +
                " | Puntaje: " + estudiante.puntaje +
                " | Estado: " + estudiante.estado
            );
        }
    }

    public static void pausar(Scanner scanner) {
        System.out.print("\nPresione Enter para continuar...");
        scanner.nextLine();
    }

    public static void mostrarMenu() {
        System.out.println("\nSeleccione una opción:");
        System.out.println("1. Mostrar estudiantes");
        System.out.println("2. Calcular promedio");
        System.out.println("3. Contar quien paso y quien no");
        System.out.println("4. Buscar por código");
        System.out.println("5. Ordenar por puntaje");
        System.out.println("6. Obtener mayor puntaje");
        System.out.println("7. Obtener menor puntaje");
        System.out.println("8. Validar puntaje");
        System.out.println("9. Salir");
        System.out.print("Opción: ");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Estudiante[] estudiantes = {
            new Estudiante("E001", "Ana López", "Informática", 85),
            new Estudiante("E002", "Carlos Gómez", "Informática", 58),
            new Estudiante("E003", "María Torres", "Electrónica", 92),
            new Estudiante("E004", "José Martínez", "Informática", 47),
            new Estudiante("E005", "Lucía Fernández", "Civil", 76),
            new Estudiante("E006", "Pedro González", "Electrónica", 63),
            new Estudiante("E007", "Sofía Benítez", "Informática", 99),
            new Estudiante("E008", "Miguel Ruiz", "Civil", 34),
            new Estudiante("E009", "Laura Cáceres", "Informática", 68),
            new Estudiante("E010", "Diego Pereira", "Electrónica", 55),
            new Estudiante("E011", "Valeria Acosta", "Civil", 81),
            new Estudiante("E012", "Fernando Rojas", "Informática", 40),
            new Estudiante("E013", "Camila Duarte", "Electrónica", 73),
            new Estudiante("E014", "Rodrigo Sosa", "Civil", 61),
            new Estudiante("E015", "Elena Franco", "Informática", 89)
        };

        boolean salir = false;

        while (!salir) {
            mostrarMenu();
            String opcion = scanner.nextLine();

            if (opcion.equals("1")) {
                mostrarEstudiantes(estudiantes);
                pausar(scanner);

            } else if (opcion.equals("2")) {
                double promedio = calcularPromedio(estudiantes);
                System.out.printf("\nPromedio general: %.2f\n", promedio);
                pausar(scanner);

            } else if (opcion.equals("3")) {
                int[] estados = contarEstados(estudiantes);
                System.out.println("\nCantidad de aprobados: " + estados[0]);
                System.out.println("Cantidad de reprobados: " + estados[1]);
                pausar(scanner);

            } else if (opcion.equals("4")) {
                System.out.println("\nBÚSQUEDA DE ESTUDIANTE POR CÓDIGO");
                System.out.print("Ingrese el código del estudiante: ");
                String codigoBuscado = scanner.nextLine();

                Estudiante resultado = buscarPorCodigo(estudiantes, codigoBuscado);

                if (resultado != null) {
                    System.out.println("Estudiante encontrado:");
                    imprimirEstudiante(resultado);
                } else {
                    System.out.println("Error: no existe un estudiante con el código " + codigoBuscado);
                }

                pausar(scanner);

            } else if (opcion.equals("5")) {
                System.out.println("\nESTUDIANTES ORDENADOS POR PUNTAJE DE MAYOR A MENOR");
                ordenarPorPuntaje(estudiantes);
                mostrarEstudiantes(estudiantes);
                pausar(scanner);

            } else if (opcion.equals("6")) {
                System.out.println("\nESTUDIANTE CON MAYOR PUNTAJE");
                Estudiante mayor = obtenerMayorPuntaje(estudiantes);
                imprimirEstudiante(mayor);
                pausar(scanner);

            } else if (opcion.equals("7")) {
                System.out.println("\nESTUDIANTE CON MENOR PUNTAJE");
                Estudiante menor = obtenerMenorPuntaje(estudiantes);
                imprimirEstudiante(menor);
                pausar(scanner);

            } else if (opcion.equals("8")) {
                System.out.println("\nVALIDACIÓN DE PUNTAJE");

                try {
                    System.out.print("Ingrese un puntaje para validar: ");
                    int puntajePrueba = Integer.parseInt(scanner.nextLine());

                    if (validarPuntaje(puntajePrueba)) {
                        System.out.println("El puntaje " + puntajePrueba + " es válido.");
                    } else {
                        System.out.println("Error: el puntaje " + puntajePrueba + " está fuera del rango permitido.");
                    }

                } catch (NumberFormatException e) {
                    System.out.println("Error: debe ingresar un número entero.");
                }

                pausar(scanner);

            } else if (opcion.equals("9")) {
                System.out.println("Saliendo del programa...");
                salir = true;

            } else {
                System.out.println("Opción inválida.");
                pausar(scanner);
            }
        }

        scanner.close();
    }
}