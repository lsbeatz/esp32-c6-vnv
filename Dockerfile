ARG BASE_OS=ubuntu
ARG BASE_DISTRO=24.04
FROM ${BASE_OS}:${BASE_DISTRO}

RUN    apt-get update        \
    && apt-get upgrade --yes \
    && apt-get install --yes \
       autoconf              \
       automake              \
       autotools-dev         \
       curl                  \
       python3               \
       python3-pip           \
       python3-tomli         \
       libmpc-dev            \
       libmpfr-dev           \
       libgmp-dev            \
       gawk                  \
       build-essential       \
       bison                 \
       flex                  \
       texinfo               \
       gperf                 \
       libtool               \
       patchutils            \
       bc                    \
       zlib1g-dev            \
       libexpat-dev          \
	   ninja-build           \
       git                   \
	   cmake                 \
	   libglib2.0-dev        \
	   libslirp-dev

ENV RISCV=/opt/riscv
ENV PATH=$PATH:$RISCV/bin

ARG TOOLCHAIN_VERSION=2024.12.16
RUN    git clone --recursive https://github.com/riscv/riscv-gnu-toolchain -b ${TOOLCHAIN_VERSION} \
    && cd riscv-gnu-toolchain                                                                     \
    && ./configure --prefix=$RISCV --with-arch=rv32imac --with-abi=ilp32                          \
    && make                                                                                       \
    && cd ..                                                                                      \
    && rm -rf riscv-gnu-toolchain
