# RESPALDO DE TODO EL REPO TP DEL PROFESOR ERASMO (solo esta hasta cierto punto)

# 📚 TP — BACKUP

> Repositorio **Legacy** para la conservación, organización y consulta de material académico de diferentes cursos.

Este repositorio centraliza material teórico, clases y recursos utilizados durante los cursos, manteniendo cada curso independiente mediante **Git Submodules**.

> [!NOTE]
> Este repositorio tiene fines **educativos y académicos** y no busca monetizar ni lucrar con el material compartido.

---

## 📑 Contenido

* [📚 Cursos](#-cursos)
* [🗂️ Estructura](#️-estructura)
* [🔄 Actualización de submódulos](#-actualización-de-submódulos)
* [🔗 Repositorios relacionados](#-repositorios-relacionados)
* [🤝 Contribuciones](#-contribuciones)
* [⚠️ Consideraciones](#️-consideraciones)
* [📌 Resumen](#-resumen)

---

## 📚 Cursos

Actualmente, este repositorio incorpora los siguientes cursos mediante **Git Submodules**:

| Curso                                    | Repositorio                                                        |
| ---------------------------------------- | ------------------------------------------------------------------ |
| 🧮 **Algoritmos y Estructuras de Datos** | [AlgoED---BACKUP](https://github.com/rren-ato/AlgoED---BACKUP)     |
| 💻 **Programación 2**                    | [PROGRA-2---BACKUP](https://github.com/rren-ato/PROGRA-2---BACKUP) |

Estos repositorios mantienen su propio historial, contenido y estructura, mientras que `TP---BACKUP` funciona como punto central de acceso al material.

---

## 🗂️ Estructura

La organización actual del repositorio es:

```text
TP---BACKUP/
│
├── AlgoED---BACKUP/
│   └── 🧮 Algoritmos y Estructuras de Datos
│
└── PROGRA-2---BACKUP/
    └── 💻 Programación 2
```

Cada directorio corresponde a un **Git Submodule** vinculado a un repositorio independiente.

Esto permite que cada curso pueda evolucionar de manera independiente sin perder una estructura centralizada de acceso.

---

## 🔄 Actualización de submódulos

> [!IMPORTANT]
>
> ### ⚠️ Aviso de edición
>
> Cuando se realicen cambios en los repositorios de los cursos, es necesario actualizar los submódulos desde este repositorio.

Ejecutar:

```bash
git submodule update --remote --merge --recursive
```

Este comando actualiza los submódulos utilizando las referencias remotas configuradas y, mediante `--recursive`, también permite actualizar posibles submódulos que existan dentro de ellos.

### 🔍 Verificar los cambios

Después de ejecutar la actualización:

```bash
git status
```

También puedes comprobar el estado de los submódulos con:

```bash
git submodule status
```

Si los submódulos apuntan ahora a nuevos commits, `TP---BACKUP` registrará esos cambios como modificaciones en los submódulos.

### 💾 Guardar la actualización

Una vez verificados los cambios:

```bash
git add .
git commit -m "Update submodules"
git push
```

> [!WARNING]
> Los contenidos de cada curso deben modificarse desde **su propio repositorio**.
>
> `TP---BACKUP` únicamente mantiene la referencia al commit correspondiente de cada submódulo.

---

## 🔗 Repositorios relacionados

### 🧪 TP — Laboratorios

[**TP-**](https://github.com/rren-ato/TP-)

Repositorio orientado principalmente al **material práctico y evaluativo**, incluyendo:

* 📄 Enunciados
* 📁 Archivos de datos
* 💻 Resoluciones
* 📝 Material complementario
* 🧪 Laboratorios de diferentes años

### 💻 Material práctico — Programación 2

[**Evaluaciones-progra2**](https://github.com/jamesVLK/Evaluaciones-progra2)

Repositorio externo relacionado con **Programación 2**, que contiene material práctico del curso, incluyendo:

* 📝 Ejercicios
* 🧪 Laboratorios
* 📄 Evaluaciones

> [!NOTE]
> `Evaluaciones-progra2` **no es un submódulo** de `TP---BACKUP`. Se incluye como repositorio relacionado para facilitar el acceso al material práctico de Programación 2.

### 🧮 Algoritmos y Estructuras de Datos

[**AlgoED---BACKUP**](https://github.com/rren-ato/AlgoED---BACKUP)

Repositorio independiente utilizado como **Git Submodule** de este proyecto.

### 💻 Programación 2

[**PROGRA-2---BACKUP**](https://github.com/rren-ato/PROGRA-2---BACKUP)

Repositorio independiente utilizado como **Git Submodule** de este proyecto.

---

## 🤝 Contribuciones

Si encuentras errores, material faltante o consideras que algún recurso debería organizarse de otra manera, puedes contribuir mediante un **Pull Request** o **Issue**.

Las contribuciones pueden incluir:

* 📚 Material académico adicional.
* 📝 Correcciones de documentación.
* 🔧 Correcciones en la estructura de los repositorios.
* 🔗 Actualizaciones de referencias.
* 📂 Organización del contenido.

> Se recomienda describir claramente los cambios realizados y, cuando corresponda, indicar a qué curso o submódulo afectan.

---

## ⚠️ Consideraciones

Este repositorio tiene fines **educativos y académicos**.

El material se conserva y comparte con el objetivo de facilitar el estudio, la consulta y la organización de recursos utilizados durante los cursos.

Se recomienda utilizar el material como **apoyo al aprendizaje** y procurar resolver las actividades por cuenta propia antes de consultar soluciones o respuestas.

> [!CAUTION]
> Si algún material publicado infringe derechos de autor, contiene información que no debería estar disponible públicamente o fue publicado accidentalmente, puede solicitarse su revisión o retiro mediante un **Issue** o **Pull Request**.

---

## 📌 Resumen

```text
                              📚 TP---BACKUP
                            Repositorio Legacy
                         Material teórico / clases
                                   │
                         ┌─────────┴─────────┐
                         │                   │
                  Git Submodule       Git Submodule
                         │                   │
                         ▼                   ▼
              ┌─────────────────┐   ┌──────────────────┐
              │ AlgoED---BACKUP │   │PROGRA-2---BACKUP │
              │       🧮        │   │        💻        │
              └─────────────────┘   └──────────────────┘
                         │                   │
                         │                   │
                         └─────────┬─────────┘
                                   │
                            Material teórico


                         ┌──────────────────┐
                         │       TP-        │
                         │       🧪         │
                         │ Material práctico│
                         └────────┬─────────┘
                                  │
                                  ▼
                       ┌──────────────────────┐
                       │ Evaluaciones-progra2 │
                       │    💻 Prog. 2        │
                       │ Ejercicios / Labs    │
                       └──────────────────────┘
```

### 🧭 En resumen

**`TP---BACKUP`** → 📚 Material teórico y repositorios Legacy
**`AlgoED---BACKUP`** → 🧮 Material teórico de Algoritmos y Estructuras de Datos
**`PROGRA-2---BACKUP`** → 💻 Material teórico de Programación 2
**`TP-`** → 🧪 Laboratorios, evaluaciones, datos y resoluciones
**`Evaluaciones-progra2`** → 💻 Ejercicios, laboratorios y evaluaciones de Programación 2
