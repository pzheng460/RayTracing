# Bidirectional Path Tracing

## Introduction

This program provides a detailed implementation of a fundamental paper in rendering, focusing on Bidirectional Path Tracing (BDPT), Multiple Importance Sampling (MIS). The whole project is written in pure C++ based on the architecture of path tracing assignment from GAMES101 by Prof. Lingqi Yan (UCSB).

## Example

![BidirectionalPathTracing](images/BidirectionalPathTracing.jpg)

*Figure 1: Bidirectional Path Tracing.*

## Tutorial

Create a build file folder in the directory:
```bash
mkdir build
```

Enter the build file folder:
```bash
cd build
```

Running cmake file:
```bash
cmake ..
```

Compile the project:
```bash
make
```

Run the project:
```bash
./BidirectionalPathTracing
```

An image file named `binary.ppm` would appear in the directory.

## Theory

### Bidirectional Path Tracing Architecture

#### Path Weight Calculation

For a path $x = x_0x_1x_2x_3x_4$:

$$ f_j(x) = L_e(x_0 \rightarrow x_1) G(x_0 \leftrightarrow x_1) f_s(x_0 \rightarrow x_1 \rightarrow x_2) G(x_1 \leftrightarrow x_2) f_s(x_1 \rightarrow x_2 \rightarrow x_3) G(x_2 \leftrightarrow x_3) f_s(x_2 \rightarrow x_3 \rightarrow x_4) G(x_3 \leftrightarrow x_4) W_e(x_3 \rightarrow x_4) $$

#### Unweighted Path

The unweighted contribution can be written as $C^*_{s,t}$:

$$ \frac{f_j(x_{s,t})}{p_{s,t}(x_{s,t})} \equiv \alpha^L_s c_{s,t} \alpha^E_t $$

#### Path Weights

Using power heuristic weights:

$$ w_k(p_s) = \frac{p_s^2}{\sum_i p_i^2} = \frac{1}{\sum_i \left(\frac{p_i}{p_s}\right)^2} $$

### Importance Flow and Radiance Flow

The light transport equation:

$$ L_o(x, \omega_o) = L_e(x, \omega_o) + \int_{S^2} L_o(M(x, \omega_i), -\omega_i) f_s(x, \omega_i \rightarrow \omega_o) d\sigma^\perp_x(\omega_i) $$

Importance transfer for sensors:

$$ W(x, \omega_o) = W_e(x, \omega_o) + \int_{S^2} W(M(x, \omega_i), -\omega_i) f_s(x, \omega_o \rightarrow \omega_i) d\sigma^\perp_x(\omega_i) $$

## Notice

This project is still under development. More features will be added in the future. And there might be still some bugs in the implementation of the BDPT algorithm.

## References

1. Veach E. "Robust Monte Carlo Methods for Light Transport Simulation," Ph.D. thesis, Stanford University Department of Computer Science, 1998.
2. Arvo, J. "Analytic Methods for Simulated Light Transport," Ph.D. thesis, Yale University, 1995.
