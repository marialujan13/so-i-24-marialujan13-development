/**
 * @file main.c
 * @brief Entry point of the system
 */

#include "expose_metrics.h"
#include <stdbool.h>

/**
 * @def SLEEP_TIME
 * Tiempo de espera entre actualizaciones en segundos.
 */
#define SLEEP_TIME 1

/**
 * @brief Función principal del programa.
 * @param argc Número de argumentos.
 * @param argv Lista de argumentos.
 * @return Código de salida del programa.
 */
int main(int argc, char* argv[])
{

    // Creamos un hilo para exponer las métricas vía HTTP
    pthread_t tid;
    if (pthread_create(&tid, NULL, expose_metrics, NULL) != 0)
    {
        fprintf(stderr, "Error al crear el hilo del servidor HTTP\n");
        return EXIT_FAILURE;
    }

    init_metrics(); // Inicializa las métricas

    // Bucle principal para actualizar las métricas cada segundo
    while (true)
    {
        update_cpu_gauge();
        update_memory_gauge();
        update_disk_io_gauge();
        update_network_usage_gauge();
        update_process_count_gauge();
        update_context_switches_gauge();
        sleep(SLEEP_TIME);
    }

    return EXIT_SUCCESS;
}
