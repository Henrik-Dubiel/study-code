#include <stdio.h>

#define MAX_SAMPLES 3000

typedef struct
{
    float time;
    double probability;
} SensorData;

typedef struct
{
    int id;
    double threshold;
    SensorData data[MAX_SAMPLES];
    int object_detection[MAX_SAMPLES];
    int sample_count;
} Sensor;

int read_sensor_file(Sensor *p_sensor, const char *filename)
{
    FILE *p_file = fopen(filename, "r");
    if (p_file == NULL)
    {
        printf("Fehler: Datei konnte nicht geoeffnet werden: %s\n", filename);
        return 1;
    }

    int i = 0;
    float t = 0.0f;
    double p = 0.0;

    while (i < MAX_SAMPLES && fscanf(p_file, "%f %lf", &t, &p) == 2)
    {
        p_sensor->data[i].time = t;
        p_sensor->data[i].probability = p;
        i++;
    }

    p_sensor->sample_count = i;

    fclose(p_file);
    return 0;
}

void compute_detection(Sensor *p_sensor)
{
    for (int i = 0; i < p_sensor->sample_count; i++)
    {
        if (p_sensor->data[i].probability > p_sensor->threshold)
        {
            p_sensor->object_detection[i] = 1;
        }
        else
        {
            p_sensor->object_detection[i] = 0;
        }
    }
}

void print_intervals_for_signal(const char *title, const Sensor *time_base, const int *signal, int n)
{
    printf("%s\n", title);

    int in_interval = 0;
    int start_idx = 0;

    for (int i = 0; i < n; i++)
    {
        if (signal[i] == 1 && in_interval == 0)
        {
            start_idx = i;
            in_interval = 1;
        }
        else if (signal[i] == 0 && in_interval == 1)
        {
            int end_idx = i - 1;
            printf("Start: %.2f s End: %.2f s\n",
                   time_base->data[start_idx].time,
                   time_base->data[end_idx].time);
            in_interval = 0;
        }
    }

    if (in_interval == 1 && n > 0)
    {
        int end_idx = n - 1;
        printf("Start: %.2f s End: %.2f s\n",
               time_base->data[start_idx].time,
               time_base->data[end_idx].time);
    }
}

int min_int(int a, int b)
{
    return (a < b) ? a : b;
}

int main(void)
{
    Sensor sensor1;
    Sensor sensor2;

    sensor1.id = 1;
    sensor1.threshold = 0.8;
    sensor1.sample_count = 0;

    sensor2.id = 2;
    sensor2.threshold = 0.7;
    sensor2.sample_count = 0;

    if (read_sensor_file(&sensor1, "sensor1.txt") != 0)
    {
        return 1;
    }
    if (read_sensor_file(&sensor2, "sensor2.txt") != 0)
    {
        return 1;
    }

    compute_detection(&sensor1);
    compute_detection(&sensor2);

    int n = min_int(sensor1.sample_count, sensor2.sample_count);

    int fused[MAX_SAMPLES];
    for (int i = 0; i < n; i++)
    {
        fused[i] = (sensor1.object_detection[i] == 1 && sensor2.object_detection[i] == 1) ? 1 : 0;
    }

    printf("--- Object Detection Results ---\n\n");

    print_intervals_for_signal("Sensor 1 detections:", &sensor1, sensor1.object_detection, sensor1.sample_count);
    printf("\n");

    print_intervals_for_signal("Sensor 2 detections:", &sensor2, sensor2.object_detection, sensor2.sample_count);
    printf("\n");

    print_intervals_for_signal("Fused signal (both sensors):", &sensor1, fused, n);

    return 0;
}