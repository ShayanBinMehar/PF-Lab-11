#include <stdio.h>
#include <math.h>

#define MAX_VERTICES 4
#define MAX_NAME_LEN 20

struct Point {
    float x;
    float y;
};

struct Shape {
    char name[MAX_NAME_LEN];
    struct Point vertices[MAX_VERTICES];
    int numVertices;
};

float calculatePerimeter(struct Shape shape) {
    float perimeter = 0.0;
    for (int i = 0; i < shape.numVertices - 1; i++) {
        perimeter += sqrt(pow(shape.vertices[i + 1].x - shape.vertices[i].x, 2) +
                           pow(shape.vertices[i + 1].y - shape.vertices[i].y, 2));
    }
    perimeter += sqrt(pow(shape.vertices[0].x - shape.vertices[shape.numVertices - 1].x, 2) +
                           pow(shape.vertices[0].y - shape.vertices[shape.numVertices - 1].y, 2));
    return perimeter;
}

float calculateArea(struct Shape shape) {
    
    if (shape.numVertices == 3) {
     
        float a = sqrt(pow(shape.vertices[1].x - shape.vertices[0].x, 2) + pow(shape.vertices[1].y - shape.vertices[0].y, 2));
        float b = sqrt(pow(shape.vertices[2].x - shape.vertices[1].x, 2) + pow(shape.vertices[2].y - shape.vertices[1].y, 2));
        float c = sqrt(pow(shape.vertices[0].x - shape.vertices[2].x, 2) + pow(shape.vertices[0].y - shape.vertices[2].y, 2));
        float s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    } else if (shape.numVertices == 4) {
       
        float width = fabs(shape.vertices[1].x - shape.vertices[0].x);
        float height = fabs(shape.vertices[1].y - shape.vertices[0].y);
        return width * height;
    } else {
        return 0.0; 
    }
}

struct Shape findLargestShape(struct Shape shapes[], int n) {
    struct Shape largestShape = shapes[0];
    for (int i = 1; i < n; i++) {
        if (calculateArea(shapes[i]) > calculateArea(largestShape)) {
            largestShape = shapes[i];
        }
    }
    return largestShape;
}

int isPointInsideRectangle(struct Shape rectangle, struct Point point) {
    if (rectangle.numVertices != 4) {
        return 0; 
    }

    float x1 = rectangle.vertices[0].x;
    float y1 = rectangle.vertices[0].y;
    float x2 = rectangle.vertices[1].x;
    float y2 = rectangle.vertices[1].y;

    return point.x >= x1 && point.x <= x2 && point.y >= y1 && point.y <= y2;
}

int main() {
    int n;
    printf("Enter the number of shapes: ");
    scanf("%d", &n);

    struct Shape shapes[n];

    for (int i = 0; i < n; i++) {
        inputShape(&shapes[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("Shape %d:\n", i + 1);
        printf("Name: %s\n", shapes[i].name);
        printf("Perimeter: %.2f\n", calculatePerimeter(shapes[i]));
        printf("Area: %.2f\n", calculateArea(shapes[i]));
    }

    struct Shape largestShape = findLargestShape(shapes, n);
    printf("\nShape with the largest area:\n");
    printf("Name: %s\n", largestShape.name);
    printf("Area: %.2f\n", calculateArea(largestShape));

  
    struct Point point = {5, 5};
    if (isPointInsideRectangle(shapes[0], point)) {
        printf("Point lies inside the rectangle.\n");
    } else {
        printf("Point does not lie inside the rectangle.\n");
    }

    return 0;
}