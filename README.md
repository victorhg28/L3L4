# L3L4
# Generador de comandos para filtros IPv4

![Static Badge](https://img.shields.io/badge/estado-en_desarrollo-green)
![Static Badge](https://img.shields.io/badge/disponible_para-linux-white)
![Static Badge](https://img.shields.io/badge/disponible_para-windows-white)

## Sobre el programa
Programa desarrollado en C++ que genera automaticamente comandos en formato MML(man-machine language) para añadir filtros IPv4 con los parametros deseados (el resultado se genera en un archivo de texto).

## Nota
Las ip's adjuntadas son ficticias y solo tienen el propósito de demostrar el correcto uso del programa.

## Contexto
El programa fue desarrollado mientras se realizaban practicas pre profesionales en Claro Perú, donde una de las actividades a atender era crear y ejecutar comandos para añadir urls e ips a las configuraciones correspondientes de Claro.
Para añadir ip's a los datos de configuracion de Claro Perú es necesario generar comandos en formato MML que puede contener condiciones de filtrado como el protocolo de Capa 3/Capa 4, el número de puerto de origen, el número de puerto de destino, la dirección IPv4 de origen y la dirección IPv4 de destino. Después de recibir los paquetes de datos, CloudUGW *(parte de la solución llamada "CloudEdge" que brinda Huawei a Claro como soporte)* los compara con un filtro, encuentra la regla correspondiente y luego aplica las políticas de cobro y acción correspondientes a la regla a los paquetes.

Estos comandos son ejecutados en las plataformas de Huawei, que dan soporte a Claro en estas actividades. El usuario interno ingresa requerimientos pidiendo que se realize lo solicitado, dichos requerimientos pueden llegar a tener gran cantidad de ip's y/o urls para distitintos puertos y protocolos, por lo que el objetivo de este desarrollo fué poder automatizar la generacion de los comandos respectivos.

## Uso
1.  Cree un archivo de texto con las ip's y mascaras a configurar, separadas por saltos de linea (es importante que especifique la mascara)

    ![file ips](https://github.com/victorhg28/L3L4/assets/53150635/4833b0be-d050-4b78-9a45-5158b25c22a2)

2. Abrir el ejecutable que se encuentra en la carpeta "Descargas" (descargue segun su SO, ya sea Windows o Ubuntu)

    ![1](https://github.com/victorhg28/L3L4/assets/53150635/538925d1-5ae0-40e3-bb0e-d1fc727e2136)
 
4.  Cargue el archivo creado anteriormente arrastrandolo y soltandolo en la ventana, llene los campos solicitados y finalmente haga click en el boton "Ejecutar".

    ![Uso](https://github.com/victorhg28/L3L4/assets/53150635/fa375b6a-0acd-4f73-ba21-d3dafde7f577)

5.  Listo! Se generará el resultado en un archivo de texto en la misma ruta donde esté el ejecutable del programa.

## Utilidad
El software desarrollado puede ser de utilidad en caso se necesite realizar configuraciones similares para otros operadores, por lo general del area de telecomunicaciones.

## Herramientas utilizadas
- U++ (IDE y framework para desarrollo de software en el lenguaje C++)
- HedEx Lite (Plataforma de documentación de Huawei)
