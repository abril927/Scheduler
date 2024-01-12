// Arduino IDE 2 no puede abrir un proyecto si no contiene un archivo .ino con el mismo nombre que el proyecto.
// Por esto, para abrir Scheduler en Arduino IDE 2, deberas abrir este archivo (scheduler.ino).
// 
// Este archivo no es necesario para Scheduler y solo es un ejemplo de como utilizar Scheduler.


// Arduino IDE 2 will not open a project if it does not contain a .ino file with the same name as the project.
// Therefore, to open Scheduler inside of Arduino IDE 2, you should open this file (scheduler.ino).
//
// This file is not necessary for Scheduler and is just an example on how to use Scheduler.

#define SCHEDULER_MAX_TASKS 2
#include <Scheduler.h>

// Initialize scheduler
// Inicializar scheduler
Scheduler scheduler;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  toggleLed();
}

bool state = false;
void toggleLed() {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));

  // Use scheduler to repeat this function in a bit
  // Usar scheduler para repetir esta funcion en un poco
  scheduler.Add(Task(500, toggleLed));
}

void loop() {
  // scheduler.Tick(); must be called in the main loop of the sketch/program
  // scheduler.Tick(); debe ser ejecutado en el bucle principal del sketch/programa
  scheduler.Tick();
}