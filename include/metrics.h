/**
 * @file metrics.h
 * @brief Funciones para obtener el uso de CPU y memoria desde el sistema de archivos /proc.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * @def BUFFER_SIZE
 * Tamaño del buffer utilizado para leer datos.
 */
#define BUFFER_SIZE 256

/**
 * @brief Obtiene el porcentaje de uso de memoria desde /proc/meminfo.
 *
 * Lee los valores de memoria total y disponible desde /proc/meminfo y calcula
 * el porcentaje de uso de memoria.
 *
 * @return Uso de memoria como porcentaje (0.0 a 100.0), o -1.0 en caso de error.
 */
double get_memory_usage();

/**
 * @brief Obtiene las estadísticas de I/O de disco.
 * @return El total de sectores leídos y escritos.
 */
double get_disk_io();

/**
 * @brief Obtiene las estadísticas de uso de red.
 * @return El uso de red en GB.
 */
double get_network_stats();

/**
 * @brief Obtiene el conteo de procesos en ejecución.
 * @return El número de procesos en ejecución.
 */
int get_process_count();

/**
 * @brief Obtiene el número de cambios de contexto.
 * @return El número de cambios de contexto.
 */
int get_context_switches();

/**
 * @brief Obtiene el porcentaje de uso de CPU desde /proc/stat.
 *
 * Lee los tiempos de CPU desde /proc/stat y calcula el porcentaje de uso de CPU
 * en un intervalo de tiempo.
 *
 * @return Uso de CPU como porcentaje (0.0 a 100.0), o -1.0 en caso de error.
 */
double get_cpu_usage();
