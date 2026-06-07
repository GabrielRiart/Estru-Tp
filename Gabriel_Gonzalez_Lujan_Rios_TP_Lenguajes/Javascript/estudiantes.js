// Trabajo Práctico - Procesamiento de registros académicos
// Lenguaje: JavaScript

const readline = require("readline");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

function preguntar(texto) {
    return new Promise((resolve) => {
        rl.question(texto, (respuesta) => {
            resolve(respuesta);
        });
    });
}

// Calculo para saber si esta aplazado o no
function calcularEstado(puntaje) {
    if (puntaje >= 60) {
        return "Aprobado";
    } else {
        return "Reprobado";
    }
}

// Confirmar puntaje correcto
function validarPuntaje(puntaje) {
    return puntaje >= 0 && puntaje <= 100;
}

// Listado de estudiantes completo
function mostrarEstudiantes(estudiantes) {
    if (estudiantes.length === 0) {
        console.log("Error: la lista de estudiantes está vacía.");
        return;
    }

    console.log("\nLISTA DE ESTUDIANTES");
    console.log("-".repeat(70));

    for (let i = 0; i < estudiantes.length; i++) {
        imprimirEstudiante(estudiantes[i]);
    }
}

// Calculo del promedio general de los estudiantes
function calcularPromedio(estudiantes) {
    if (estudiantes.length === 0) {
        console.log("Error: no se puede calcular el promedio de una lista vacía.");
        return 0;
    }

    let suma = 0;

    for (let i = 0; i < estudiantes.length; i++) {
        suma += estudiantes[i].puntaje;
    }

    return suma / estudiantes.length;
}

// Cuantos estan aplazados y cuantos aprobados
function contarEstados(estudiantes) {
    let aprobados = 0;
    let reprobados = 0;

    for (let i = 0; i < estudiantes.length; i++) {
        if (estudiantes[i].estado === "Aprobado") {
            aprobados++;
        } else {
            reprobados++;
        }
    }

    return [aprobados, reprobados];
}

// Buscar estudiante especifico
function buscarPorCodigo(estudiantes, codigo) {
    for (let i = 0; i < estudiantes.length; i++) {
        if (estudiantes[i].codigo === codigo) {
            return estudiantes[i];
        }
    }

    return null;
}

// Top de los estudiantes
function ordenarPorPuntaje(estudiantes) {
    // Ordenamiento burbuja manual de mayor a menor
    let n = estudiantes.length;

    for (let i = 0; i < n - 1; i++) {
        for (let j = 0; j < n - i - 1; j++) {
            if (estudiantes[j].puntaje < estudiantes[j + 1].puntaje) {
                let aux = estudiantes[j];
                estudiantes[j] = estudiantes[j + 1];
                estudiantes[j + 1] = aux;
            }
        }
    }
}

// Mejor estudiante
function obtenerMayorPuntaje(estudiantes) {
    if (estudiantes.length === 0) {
        return null;
    }

    let mayor = estudiantes[0];

    for (let i = 0; i < estudiantes.length; i++) {
        if (estudiantes[i].puntaje > mayor.puntaje) {
            mayor = estudiantes[i];
        }
    }

    return mayor;
}

// Peor estudiante
function obtenerMenorPuntaje(estudiantes) {
    if (estudiantes.length === 0) {
        return null;
    }

    let menor = estudiantes[0];

    for (let i = 0; i < estudiantes.length; i++) {
        if (estudiantes[i].puntaje < menor.puntaje) {
            menor = estudiantes[i];
        }
    }

    return menor;
}

// Imprimir un estudiante específico
function imprimirEstudiante(estudiante) {
    if (estudiante === null) {
        console.log("No se encontró el estudiante.");
    } else {
        console.log(
            "Código: " + estudiante.codigo +
            " | Nombre: " + estudiante.nombre +
            " | Carrera: " + estudiante.carrera +
            " | Puntaje: " + estudiante.puntaje +
            " | Estado: " + estudiante.estado
        );
    }
}

async function pausar() {
    await preguntar("\nPresione Enter para continuar...");
}

function mostrarMenu() {
    console.log("\nSeleccione una opción:");
    console.log("1. Mostrar estudiantes");
    console.log("2. Calcular promedio");
    console.log("3. Contar quien paso y quien no");
    console.log("4. Buscar por código");
    console.log("5. Ordenar por puntaje");
    console.log("6. Obtener mayor puntaje");
    console.log("7. Obtener menor puntaje");
    console.log("8. Validar puntaje");
    console.log("9. Salir");
}

// Programa principal
async function main() {
    let estudiantes = [
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
    ];

    // Calcular automáticamente el estado y validar puntajes
    for (let i = 0; i < estudiantes.length; i++) {
        if (validarPuntaje(estudiantes[i].puntaje)) {
            estudiantes[i].estado = calcularEstado(estudiantes[i].puntaje);
        } else {
            estudiantes[i].estado = "Puntaje inválido";
        }
    }

    let salir = false;

    while (!salir) {
        mostrarMenu();
        let opcion = await preguntar("Opción: ");

        if (opcion === "1") {
            mostrarEstudiantes(estudiantes);
            await pausar();

        } else if (opcion === "2") {
            let promedio = calcularPromedio(estudiantes);
            console.log("\nPromedio general:", promedio.toFixed(2));
            await pausar();

        } else if (opcion === "3") {
            let estados = contarEstados(estudiantes);
            console.log("Cantidad de aprobados:", estados[0]);
            console.log("Cantidad de reprobados:", estados[1]);
            await pausar();

        } else if (opcion === "4") {
            console.log("\nBÚSQUEDA DE ESTUDIANTE POR CÓDIGO");

            let codigoBuscado = await preguntar("Ingrese el código del estudiante: ");
            let resultado = buscarPorCodigo(estudiantes, codigoBuscado);

            if (resultado !== null) {
                console.log("Estudiante encontrado:");
                imprimirEstudiante(resultado);
            } else {
                console.log("Error: no existe un estudiante con el código", codigoBuscado);
            }

            await pausar();

        } else if (opcion === "5") {
            console.log("\nESTUDIANTES ORDENADOS POR PUNTAJE DE MAYOR A MENOR");
            ordenarPorPuntaje(estudiantes);
            mostrarEstudiantes(estudiantes);
            await pausar();

        } else if (opcion === "6") {
            console.log("\nESTUDIANTE CON MAYOR PUNTAJE");
            let mayor = obtenerMayorPuntaje(estudiantes);
            imprimirEstudiante(mayor);
            await pausar();

        } else if (opcion === "7") {
            console.log("\nESTUDIANTE CON MENOR PUNTAJE");
            let menor = obtenerMenorPuntaje(estudiantes);
            imprimirEstudiante(menor);
            await pausar();

        } else if (opcion === "8") {
            console.log("\nVALIDACIÓN DE PUNTAJE");

            let entrada = await preguntar("Ingrese un puntaje para validar: ");
            let puntajePrueba = parseInt(entrada);

            if (isNaN(puntajePrueba)) {
                console.log("Error: debe ingresar un número entero.");
            } else {
                if (validarPuntaje(puntajePrueba)) {
                    console.log("El puntaje", puntajePrueba, "es válido.");
                } else {
                    console.log("Error: el puntaje", puntajePrueba, "está fuera del rango permitido.");
                }
            }

            await pausar();

        } else if (opcion === "9") {
            console.log("Saliendo del programa...");
            salir = true;

        } else {
            console.log("Opción inválida.");
            await pausar();
        }
    }

    rl.close();
}

main();