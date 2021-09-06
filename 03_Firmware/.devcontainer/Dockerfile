# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.191.0/containers/debian/.devcontainer/base.Dockerfile

# [Choice] Debian version: bullseye, buster, stretch
ARG VARIANT="buster"
FROM mcr.microsoft.com/vscode/devcontainers/base:0-${VARIANT}

WORKDIR /work

# ** [Optional] Uncomment this section to install additional packages. **
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends make bzip2 libncurses5 udev libusb-1.0.0

# Download ARM-GCC
RUN wget -qO- https://developer.arm.com/-/media/Files/downloads/gnu-rm/9-2019q4/gcc-arm-none-eabi-9-2019-q4-major-x86_64-linux.tar.bz2 | tar -xj
ENV PATH "/work/gcc-arm-none-eabi-9-2019-q4-major/bin:$PATH"

# Download J-Link debug tools
RUN wget --post-data='accept_license_agreement=accepted' https://www.segger.com/downloads/jlink/JLink_Linux_x86_64.deb
RUN dpkg -i JLink_Linux_x86_64.deb

# Download nRF Command-line tools
RUN wget https://www.nordicsemi.com/-/media/Software-and-other-downloads/Desktop-software/nRF-command-line-tools/sw/Versions-10-x-x/10-14-0/nRF-Command-Line-Tools_10_14_0_Linux64.zip
RUN unzip nRF-Command-Line-Tools_10_14_0_Linux64.zip
RUN dpkg -i nRF-Command-Line-Tools_10_14_0_Linux64/nrf-command-line-tools_10.14.0_amd64.deb