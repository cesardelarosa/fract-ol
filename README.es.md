# Fract-ol

Una herramienta interactiva escrita en C que te permite explorar y visualizar una gran variedad de fractales.  
Admite tanto el modo **obligatorio** (julia, mandelbrot) como un modo **bonus** con fractales adicionales:  
**burning_ship, multibrot, tricorn, celtic, buffalo**.

---

## 1. Clonar, Compilar y Ejecutar

### Clonar el Repositorio

Para clonar el proyecto (recuerda clonar de forma recursiva para obtener los submódulos):
```bash
git clone --recursive https://github.com/cesardelarosa/fract-ol.git && cd fract-ol
```

### Compilación

El proyecto se compila con un `Makefile`.

- Para compilar la versión **obligatoria**:
```bash
make
```
- Para compilar la versión **bonus** (con fractales adicionales y opciones de color):
```bash
make bonus
```
> **Nota:** La compilación utiliza subdirectorios como `libft` y `minilibx`;  
> asegúrate de haberlos clonado correctamente.

### Ejecución

La sintaxis de ejecución es la siguiente:
```bash
./fractol <tipo_de_fractal> [<julia_cx> <julia_cy>]
```
Donde `<tipo_de_fractal>` puede ser:
- **obligatorio:** `julia`, `mandelbrot`
- **bonus:** `burning_ship`, `multibrot`, `tricorn`, `celtic`, `buffalo`

Por ejemplo, para ejecutar el fractal *buffalo*:
```bash
./fractol buffalo
```

---

## 2. Controles e Interacción

Una vez iniciado el programa (por ejemplo, con `./fractol buffalo`), se mostrarán los siguientes controles en la terminal:

- **TECLA ESC:** Finaliza la ejecución del programa.  
- **TECLA C:** Cambia la paleta de colores.  
- **TECLA R:** Restablece la posición y el zoom.  
- **Flechas:** Desplazan la vista del fractal.  
- **Rueda del ratón:** Amplía o reduce el zoom.  
- **Clic Izquierdo:** Alterna entre la versión Mandelbrot y Julia (cuando aplique).

---

## 3. Galería de Imágenes

### Paletas de Color

A continuación se muestran las distintas paletas de color disponibles, dispuestas en dos columnas:

<div align="center">
  <a href="images/color1.png">
    <img src="images/color1.png" width="412px"/>
  </a>
  <a href="images/color2.png">
    <img src="images/color2.png" width="412px"/>
  </a>
</div>

<div align="center">
  <a href="images/color3.png">
    <img src="images/color3.png" width="412px"/>
  </a>
  <a href="images/color4.png">
    <img src="images/color4.png" width="412px"/>
  </a>
</div>

### Ejemplos de Fractales

A continuación se muestran ejemplos de fractales en sus distintas versiones (Mandelbrot y Julia, cuando proceda), dispuestos de dos en dos:

- **Mandelbrot:**

<div align="center">
  <a href="images/mandelbrot_full.png">
    <img src="images/mandelbrot_full.png" width="412px"/>
  </a>
  <a href="images/mandelbrot_detail.png">
    <img src="images/mandelbrot_detail.png" width="412px"/>
  </a>
</div>

- **Julia:**

<div align="center">
  <a href="images/julia_sample1.png">
    <img src="images/julia_sample1.png" width="412px"/>
  </a>
  <a href="images/julia_sample2.png">
    <img src="images/julia_sample2.png" width="412px"/>
  </a>
</div>

- **Burning Ship:**

<div align="center">
  <a href="images/burning_ship_mandelbrot.png">
    <img src="images/burning_ship_mandelbrot.png" width="412px"/>
  </a>
  <a href="images/burning_ship_julia.png">
    <img src="images/burning_ship_julia.png" width="412px"/>
  </a>
</div>

- **Multibrot:**

<div align="center">
  <a href="images/multibrot_mandelbrot.png">
    <img src="images/multibrot_mandelbrot.png" width="412px"/>
  </a>
  <a href="images/multibrot_julia.png">
    <img src="images/multibrot_julia.png" width="412px"/>
  </a>
</div>

- **Tricorn:**

<div align="center">
  <a href="images/tricorn_mandelbrot.png">
    <img src="images/tricorn_mandelbrot.png" width="412px"/>
  </a>
  <a href="images/tricorn_julia.png">
    <img src="images/tricorn_julia.png" width="412px"/>
  </a>
</div>

- **Celtic:**

<div align="center">
  <a href="images/celtic_mandelbrot.png">
    <img src="images/celtic_mandelbrot.png" width="412px"/>
  </a>
  <a href="images/celtic_julia.png">
    <img src="images/celtic_julia.png" width="412px"/>
  </a>
</div>

- **Buffalo:**

<div align="center">
  <a href="images/buffalo_mandelbrot.png">
    <img src="images/buffalo_mandelbrot.png" width="412px"/>
  </a>
  <a href="images/buffalo_julia.png">
    <img src="images/buffalo_julia.png" width="412px"/>
  </a>
</div>

---

## 4. Matemática y Teoría de los Fractales

Los fractales son objetos que presentan auto-similitud y complejidad infinita. Matemáticamente, pueden definirse mediante la iteración de funciones complejas.

### Conjunto de Mandelbrot

El **conjunto de Mandelbrot** se define como el conjunto de puntos $c \in \mathbb{C}$ para los cuales la sucesión

$$
z_{n+1} = z_n^2 + c \quad\text{con}\; z_0 = 0
$$

permanece acotada, es decir:

$$
\limsup_{n \to \infty} |z_n| < \infty.
$$

Su frontera es famosa por su estructura infinitamente rica.

### Conjunto de Julia

Para un parámetro fijo $c$, el **conjunto de Julia** se define como:

$$
J(c) = \{ z_0 \in \mathbb{C} \mid \{z_{n+1} = z_n^2 + c\}\text{ no diverge} \}.
$$

Una propiedad clave es:

- Si $c$ pertenece al conjunto de Mandelbrot, entonces $J(c)$ es conexo.  
- Si $c$ no pertenece al conjunto de Mandelbrot, $J(c)$ es disconexo (a menudo llamado "polvo de Julia").

### Algoritmo de Cálculo

El renderizado de fractales se basa en el **algoritmo de tiempo de escape**:

1. **Mapeo de píxeles al plano complejo:**  
   Cada píxel $(x,y)$ se transforma en un número complejo $z_0$ o se utiliza como $c$, dependiendo del fractal.

2. **Iteración:**  
   Se aplica recursivamente $f(z) = z^2 + c$ (o sus variantes para otros fractales).

3. **Condición de escape:**  
   Se cuenta el número de iteraciones $n$ hasta que $|z_n|$ supera un umbral (por ejemplo, 2). Si $n$ llega al valor máximo definido, se asume que el punto está dentro del fractal.

4. **Suavizado de color:**  
   Se emplea una función de suavizado para asignar un valor continuo de iteración y lograr gradientes de color más suaves.

Otros fractales (como *burning_ship*, *multibrot*, *tricorn*, *celtic* y *buffalo*) modifican la función iterativa y/o el mapeo al plano complejo, dando lugar a patrones y simetrías únicos.

Esta implementación es ideal para estudiantes y entusiastas del análisis complejo, ya que reúne conceptos de análisis, geometría y teoría del caos en una herramienta interactiva y visualmente llamativa.

---

## 5. Estructura del Proyecto

El proyecto se organiza de la siguiente forma:

- **src/**
  - `main.c`  
    Punto de entrada para la versión obligatoria. Inicializa la aplicación y gestiona el bucle de eventos.
  - `hooks.c`  
    Maneja eventos de teclado y ratón en la versión obligatoria.
  - `parser.c`  
    Procesa los argumentos de línea de comandos y selecciona el tipo de fractal.
  - `draw.c`  
    Renderiza el fractal en la ventana, realizando iteraciones y asignando colores.
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
  Archivos de cabecera (`.h`) que contienen definiciones y prototipos utilizados en el proyecto.

- **libft/**  
  Una biblioteca de funciones auxiliares desarrollada siguiendo los estándares de 42.

- **minilibx/**  
  La biblioteca gráfica utilizada para la creación de ventanas y el manejo de gráficos.

- **images/**  
  Un directorio que contiene capturas y ejemplos visuales de los distintos fractales y paletas de color.

- **Makefile**  
  Define las reglas de compilación tanto para la versión **obligatoria** como para la **bonus**.

---

¡Explora, experimenta y déjate maravillar por la belleza infinita de los fractales!  
Si encuentras algún problema, tienes sugerencias o deseas colaborar, no dudes en abrir un *issue* o enviar un *pull request* en el repositorio:

[github.com/cesardelarosa/fract-ol](https://github.com/cesardelarosa/fract-ol)

---

## Créditos

- **Autor:** César de la Rosa (cde-la-r)  
- **Correo:** code@cesardelarosa.xyz  
- **Proyecto:** Fract-ol (Proyecto para la formación de programación en 42)

---

*¡Disfruta explorando estos infinitos universos visuales y matemáticos!*

