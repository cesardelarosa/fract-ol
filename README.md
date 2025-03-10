# Fract-ol

Una herramienta interactiva escrita en C, que permite explorar y visualizar una gran variedad de fractales.  
Soporta tanto el modo **obligatorio** (julia, mandelbrot) como un modo **bonus** con fractales adicionales:  
**burning_ship, multibrot, tricorn, celtic, buffalo**.

---

## 1. Clonar, Compilar y Ejecución

### Clonar el Repositorio

Para clonar el proyecto (recuerda clonar de forma recursiva para obtener las sublibrerías):
```bash
    git clone --recursive https://github.com/cesardelarosa/fract-ol.git && cd fract-ol
```
### Compilación

El proyecto se compila mediante `Makefile`.

- Para compilar la versión **obligatoria**:
```bash
        make
```
- Para compilar la versión **bonus** (con fractales adicionales y opciones de color):
```bash
        make bonus
```
> **Nota:** La compilación utiliza subdirectorios como `libft` y `minilibx`;  
> asegúrate de tenerlos correctamente clonados.

### Ejecución

La sintaxis de ejecución es la siguiente:
```bash
    ./fractol <fractal_type> [<julia_cx> <julia_cy>]
```
Donde `<fractal_type>` puede ser cualquiera de:
- **obligatorio:** `julia`, `mandelbrot`
- **bonus:** `burning_ship`, `multibrot`, `tricorn`, `celtic`, `buffalo`

Por ejemplo, para ejecutar el fractal *buffalo*:
```bash
    ./fractol buffalo
```
---

## 2. Manejo e Interacción

Una vez iniciado el programa (por ejemplo, con `./fractol buffalo`), se muestran en la terminal los controles disponibles:


- **ESC KEY:** Finaliza la ejecución del programa.  
- **C KEY:** Cambia la paleta de colores.  
- **R KEY:** Resetea la posición y el zoom.  
- **Flechas (ARROWS):** Mueven la vista del fractal.  
- **MOUSE WHEEL:** Realiza zoom in/zoom out.  
- **LEFT CLICK:** Alterna entre la versión Mandelbrot y la versión Julia (si procede).

---

## 3. Galería de Imágenes

### Opciones de Colores

Puedes observar las distintas paletas de colores disponibles (los archivos de imagen se encuentran en el directorio `images/`):

- [Color 1](images/color1.png)  
- [Color 2](images/color2.png)  
- [Color 3](images/color3.png)  
- [Color 4](images/color4.png)  

### Opciones de Fractales

A continuación, se muestran ejemplos de fractales en sus distintas versiones (Mandelbrot y Julia, cuando aplica):

- **Mandelbrot:**
  - [Mandelbrot - Vista Completa](images/mandelbrot_full.png)
  - [Mandelbrot - Detalle](images/mandelbrot_detail.png)
  
- **Julia:**
  - [Julia - Ejemplo 1](images/julia_sample1.png)
  - [Julia - Ejemplo 2](images/julia_sample2.png)

- **Burning Ship:**
  - [Burning Ship - Mandelbrot](images/burning_ship_mandelbrot.png)
  - [Burning Ship - Julia](images/burning_ship_julia.png)

- **Multibrot:**
  - [Multibrot - Mandelbrot](images/multibrot_mandelbrot.png)
  - [Multibrot - Julia](images/multibrot_julia.png)

- **Tricorn:**
  - [Tricorn - Mandelbrot](images/tricorn_mandelbrot.png)
  - [Tricorn - Julia](images/tricorn_julia.png)

- **Celtic:**
  - [Celtic - Mandelbrot](images/celtic_mandelbrot.png)
  - [Celtic - Julia](images/celtic_julia.png)

- **Buffalo:**
  - [Buffalo - Mandelbrot](images/buffalo_mandelbrot.png)
  - [Buffalo - Julia](images/buffalo_julia.png)

Haz clic en cada enlace para ver la imagen en tamaño completo.

---

## 4. Matemáticas y Teoría de los Fractales

Los fractales son objetos que presentan auto-similitud y complejidad infinita. Matemáticamente, se pueden definir mediante iteraciones de funciones complejas.

### Conjunto de Mandelbrot

El **conjunto de Mandelbrot** se define como el conjunto de puntos \( c \in \mathbb{C} \) para los cuales la sucesión

\[
z_{n+1} = z_n^2 + c \quad \text{con } z_0 = 0
\]

se mantiene acotada, es decir:

\[
\limsup_{n \to \infty} |z_n| < \infty.
\]

La complejidad de su borde es famosa por generar estructuras infinitamente ricas en detalle.

### Conjunto de Julia

Para un parámetro \( c \) fijo, el **conjunto de Julia** se define como:

\[
J(c) = \{ z_0 \in \mathbb{C} \mid \{z_{n+1} = z_n^2 + c\} \text{ no diverge} \}.
\]

Una propiedad fundamental es que:

- Si \( c \) pertenece al conjunto de Mandelbrot, entonces \( J(c) \) es conexo.  
- Si \( c \) no pertenece al conjunto de Mandelbrot, \( J(c) \) es desconexo (a menudo llamado "polvo de Julia").

### Algoritmo de Cálculo

La renderización de fractales se basa en el **algoritmo de tiempo de escape**:

1. **Mapeo de píxeles al plano complejo:**  
   Cada píxel \((x,y)\) se transforma en un número complejo \( z_0 \) o se utiliza como \( c \), según el fractal.

2. **Iteración:**  
   Se aplica recursivamente la función \( f(z) = z^2 + c \) (o sus variantes para otros fractales).

3. **Condición de escape:**  
   Se cuenta el número de iteraciones \( n \) hasta que \( |z_n| \) supera un umbral (por ejemplo, 2). Si \( n \) alcanza el valor máximo definido, se asume que el punto pertenece al fractal.

4. **Suavizado de colores:**  
   Se utiliza una función de suavizado para asignar un valor continuo de iteración y obtener gradientes de color más suaves.

Otros fractales (como *burning_ship*, *multibrot*, *tricorn*, *celtic* y *buffalo*) modifican la función iterativa y/o el mapeo al plano complejo, lo que resulta en patrones y simetrías propias de cada uno.

Esta implementación es ideal para estudiantes y entusiastas del cálculo complejo, ya que une conceptos de análisis, geometría y teoría del caos en una herramienta interactiva y visualmente atractiva.

---

## 5. Estructura del Proyecto

El proyecto se organiza de la siguiente manera:

- **src/**
  - `main.c`  
    Punto de entrada para la versión obligatoria. Inicializa la aplicación y gestiona el bucle de eventos.
  - `hooks.c`  
    Maneja eventos de teclado y ratón para la versión obligatoria.
  - `parser.c`  
    Procesa los argumentos de la línea de comandos y selecciona el tipo de fractal.
  - `draw.c`  
    Renderiza el fractal en la ventana, aplicando iteraciones y asignando colores.
  - `math.c`  
    Implementa los cálculos matemáticos para los fractales *julia* y *mandelbrot*.

- **bonus/**
  - `main_bonus.c`  
    Punto de entrada para la versión bonus, con fractales adicionales y opciones extendidas.
  - `hooks_bonus.c`  
    Maneja la interacción en la versión bonus.
  - `parser_bonus.c`  
    Procesa los argumentos para el modo bonus.
  - `draw_bonus.c`  
    Renderiza los fractales en la versión bonus.
  - `math_bonus.c`, `math2_bonus.c`  
    Contienen funciones específicas para el cálculo de fractales como *burning_ship*, *multibrot*, *tricorn*, *celtic* y *buffalo*.
  - `info_bonus.c`  
    Muestra información en pantalla (tipo panel informativo).
  - `color_bonus.c`  
    Define los esquemas de color para la versión bonus.

- **include/**  
  Archivos de cabecera (`.h`) con las definiciones y prototipos usados en el proyecto.

- **libft/**  
  Biblioteca con funciones auxiliares desarrolladas según las normas de 42.

- **minilibx/**  
  Librería gráfica utilizada para la creación de ventanas y manejo de gráficos.

- **images/**  
  Directorio que contiene las capturas y ejemplos visuales de los distintos fractales y paletas de colores.

- **Makefile**  
  Define las reglas de compilación, permitiendo compilar tanto la versión **mandatory** como la **bonus**.

---

¡Explora, experimenta y déjate sorprender por la belleza infinita de los fractales!  
Si encuentras algún problema, tienes sugerencias o deseas colaborar, no dudes en abrir un *issue* o enviar un *pull request* en el repositorio:

[github.com/cesardelarosa/fract-ol](https://github.com/cesardelarosa/fract-ol)

---

## Créditos

- **Autor:** César de la Rosa (cde-la-r)  
- **Correo:** code@cesardelarosa.xyz  
- **Proyecto:** Fract-ol (Proyecto para el curso de programación en 42)

---

*¡Que disfrutes explorando estos infinitos universos visuales y matemáticos!*
