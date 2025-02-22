#include <stdio.h>
#include <math.h>

struct Point3D {
    float x, y, z;
};

struct Vehicle {
    int id;
    struct Point3D startPoint;
    struct Point3D endPoint;
    float timeTaken;
};

void inputVehicleDetails(struct Vehicle *vehicle) {
    printf("Enter vehicle ID: ");
    scanf("%d", &vehicle->id);

    printf("Enter starting point (x, y, z): ");
    scanf("%f %f %f", &vehicle->startPoint.x, &vehicle->startPoint.y, &vehicle->startPoint.z);

    printf("Enter ending point (x, y, z): ");
    scanf("%f %f %f", &vehicle->endPoint.x, &vehicle->endPoint.y, &vehicle->endPoint.z);

    printf("Enter time taken (in hours): ");
    scanf("%f", &vehicle->timeTaken);
}

float calculateDistance(struct Point3D start, struct Point3D end) {
    float dx = end.x - start.x;
    float dy = end.y - start.y;
    float dz = end.z - start.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

float calculateSpeed(struct Vehicle vehicle) {
    float distance = calculateDistance(vehicle.startPoint, vehicle.endPoint);
    return distance / vehicle.timeTaken;
}

struct Vehicle findFastestVehicle(struct Vehicle vehicles[], int n) {
    struct Vehicle fastestVehicle = vehicles[0];
    for (int i = 1; i < n; i++) {
        if (calculateSpeed(vehicles[i]) > calculateSpeed(fastestVehicle)) {
            fastestVehicle = vehicles[i];
        }
    }
    return fastestVehicle;
}

void findVehiclesWithDistanceGreaterThanThreshold(struct Vehicle vehicles[], int n, float threshold) {
    printf("Vehicles that traveled more than %.2f km:\n", threshold);
    for (int i = 0; i < n; i++) {
        float distance = calculateDistance(vehicles[i].startPoint, vehicles[i].endPoint);
        if (distance > threshold) {
            printf("Vehicle ID: %d, Distance: %.2f km, Speed: %.2f km/h\n",
                   vehicles[i].id, distance, calculateSpeed(vehicles[i]));
        }
    }
}

int main() {
    int n;
    printf("Enter the number of vehicles: ");
    scanf("%d", &n);

    struct Vehicle vehicles[n];

    for (int i = 0; i < n; i++) {
        inputVehicleDetails(&vehicles[i]);
    }

    for (int i = 0; i < n; i++) {
        float distance = calculateDistance(vehicles[i].startPoint, vehicles[i].endPoint);
        float speed = calculateSpeed(vehicles[i]);
        printf("Vehicle %d: Distance = %.2f km, Speed = %.2f km/h\n", vehicles[i].id, distance, speed);
    }

    struct Vehicle fastestVehicle = findFastestVehicle(vehicles, n);
    printf("\nFastest Vehicle:\n");
    printf("Vehicle ID: %d, Speed: %.2f km/h\n", fastestVehicle.id, calculateSpeed(fastestVehicle));

    float threshold;
    printf("Enter the distance threshold: ");
    scanf("%f", &threshold);
    findVehiclesWithDistanceGreaterThanThreshold(vehicles, n, threshold);

    return 0;
}