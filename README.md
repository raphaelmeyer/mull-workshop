# Mull Workshop

## Docs

* https://mull.readthedocs.io/
* https://github.com/mull-project/mull/

## Development container

Build the container once with

    docker build --tag mull-workshop docker/

Start development container and open a terminal

    ./env.sh

Run roman numeral converter example

    > make roman

## Exercise

In this exercise we want to add some tests to the [Gilded Rose](https://github.com/NotMyself/GildedRose) inventory system in order to safely refactor before implementing the new feature for *conjured items*.

Run gilded rose tests in the container:

    > make rose

Use mutation testing for guidance in finding test cases.
