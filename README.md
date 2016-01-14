# Bioinformatics project - Rank/Select


[![License](https://img.shields.io/packagist/l/doctrine/orm.svg)](https://img.shields.io/packagist/l/doctrine/orm.svg)

Class project for [Bioinformatics class](http://www.fer.unizg.hr/en/course/bio) on [Faculty of Electrical Engineering and Computing, University of Zagreb](http://www.fer.unizg.hr/en)


## Goal

Compressed data structures aims at representing classical data structures  in little space while keeping the functionality of the structure. In this project goal was to achive fast and accurate rank and select functions on big sequences of genomes found at [Bacteria ensamble website](http://bacteria.ensembl.org/index.html).

## Implementation

Data structures used for implementation of fast rank and select operation on big sequences are Red Black Trees with Wavelet Trees in their nodes. By choosing those two structures we can achive fast search for right subsequence of inital data O(logN) with fast rank and select operations of Wavelet tree O(logA) - where A stands for alphabet size. Project is completely done in C++.

## Usage

We provided numbers of test examples, some are randomly generated and some are genomes found at [Bacteria ensamble website](http://bacteria.ensembl.org/index.html). Results that we ran are located in `outputs/` folder and its `/bacterias_outputs` and `/tests_outputs` subfolders. Version without memory and time statistics can be found in `no_statistics_versions` folder - just move them in root folder and follow procedure.

Example of basic test usage with statistics :
````bash
    # place yourself in bioinformatics folder
    # and compile code
    g++ -std=c++0x example1000.cpp -o example1000 -lpsapi
    
    # run compiled code with right input txt file and output txt file
    example1000 < ./examples/example100.txt > ./outputs/tests_outputs/output_example1000.txt
`````

Example of basic usage without statistics :
````bash
    # place yourself in bioinformatics folder
    # and compile code
    g++ -std=c++0x example1000_no_statistics.cpp -o example1000_no_stat
    
    # run compiled code with right input txt file and output txt file
    example1000_no_stat < ./examples/example100.txt > ./outputs/tests_outputs/output_example1000_no_stat.txt
`````

## Bacterias testing with memory usage and time statistics

Pull project to your local directory ( eg. your_local_path/rank_select ) open bioinformatics folder with your console and follow next steps to see results for bacterias tested.

##### Anaplasma phagocytophilium

````bash
    # compile code
    g++ -std=c++0x anaplasma_phagocytophilum.cpp -o anaplasma -lpsapi
    
    # run compiled code with right input txt file and output txt file
    anaplasma < ./bacterias/Anaplasma_phagocytophilum.GCA_000968465.1.30.dna.toplevel.fa > ./outputs/bacterias_outputs/output_anaplasma.txt
`````

##### Echericia coli

````bash
    # compile code
    g++ -std=c++0x echericia_coli.cpp -o echericia -lpsapi
    
    # run compiled code with right input txt file and output txt file
    echericia < ./bacterias/Escherichia_coli.GCA_000967155.1.30.dna_rm.toplevel.fa > ./outputs/bacterias_outputs/output_escherichia.txt
`````

##### Salmonella enterica

````bash
    # compile code
    g++ -std=c++0x salmonella_enterica.cpp -o salmonella -lpsapi
    
    # run compiled code with right input txt file and output txt file
    salmonella < ./bacterias/Salmonella_enterica.GCA_000783815.1.30.dna.toplevel.fa > ./outputs/bacterias_outputs/output_salmonela.txt
`````

##### Mycobacterium tuberculosis

````bash
    # compile code
    g++ -std=c++0x mycobacterium_tuberculosis.cpp -o tuberculosis -lpsapi
    
    # run compiled code with right input txt file and output txt file
    tuberculosis < ./bacterias/Mycobacterium_tuberculosis_gca_000666105.GCA_000666105.1.30.dna.toplevel.fa > ./outputs/bacterias_outputs/output_tuberculosis.txt
`````

If you wish to run programs without memory usage and time statistics, just take examples that contain _no_statistics.cpp sufix and compile without -lpsapi.

License
---------
The MIT License (MIT)

Copyright (c) 2016 Valentino Perović, Stjepan Livačić, Marta Poštenjak

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.


THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.


