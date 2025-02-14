# fract-ol

Un proyecto de visualización de fractales utilizando la biblioteca MiniLibX.

---

## **Correr de una**

Descargar, compilar y ejecutar el programa en una linea y desde cero:

```bash
$ git clone --recursive https://github.com/cesardelarosa/fract-ol.git && cd fract-ol && make && ./fractol julia
```

---

## **Clonación del repositorio**

Para clonar este repositorio correctamente, incluyendo todos los submódulos necesarios, ejecuta:

```bash
git clone --recursive https://github.com/cesardelarosa/fract-ol.git && cd fract-ol
```

Si ya has clonado el repositorio sin la opción `--recursive`, puedes inicializar los submódulos con:

```bash
git submodule update --init --recursive
```

---

## **Compilación**

Para compilar el proyecto, utiliza el `Makefile` con:

```bash
make
```

Comandos disponibles en el Makefile:
- `make` : Compila el proyecto.
- `make clean` : Elimina los archivos objeto.
- `make fclean` : Elimina los archivos objeto y el ejecutable.
- `make re` : Limpia y recompila el proyecto.

---

## **Uso del programa**

Ejecuta el programa con uno de los siguientes parámetros para elegir el fractal:

```bash
./fractol julia [c.x] [c.y]   # Con parámetros opcionales para el conjunto de Julia
```
```bash
./fractol mandelbrot          # Para el conjunto de Mandelbrot
```
```bash
./fractol burningship         # Para el conjunto de Burning Ship
```

---

## **Dependencias**

Este proyecto utiliza la biblioteca [MiniLibX](https://github.com/42Paris/minilibx-linux), junto con la biblioteca propia [libft](https://github.com/cesardelarosa/libft).

---

¡Disfruta explorando fractales con fract-ol! 😊
