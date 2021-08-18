# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.191.0/containers/debian/.devcontainer/base.Dockerfile

# [Choice] Debian version: bullseye, buster, stretch
ARG VARIANT="buster"
FROM mcr.microsoft.com/vscode/devcontainers/base:0-${VARIANT}

# ** [Optional] Uncomment this section to install additional packages. **
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends curl git unzip xz-utils zip libglu1-mesa openjdk-11-jdk wget fontconfig

ENV SDKROOT /work
WORKDIR ${SDKROOT}

RUN mkdir -p Android/sdk
ENV ANDROID_SDK_ROOT ${SDKROOT}/Android/sdk
RUN mkdir -p .android && touch .android/repositories.cfg

# Set up Android SDK
ADD https://dl.google.com/android/repository/commandlinetools-linux-7583922_latest.zip sdk-tools.zip
RUN unzip sdk-tools.zip && rm sdk-tools.zip
RUN mkdir -p Android/sdk/cmdline-tools
RUN mv cmdline-tools Android/sdk/cmdline-tools/latest
RUN cd Android/sdk/cmdline-tools/latest/bin && yes | ./sdkmanager --licenses
RUN cd Android/sdk/cmdline-tools/latest/bin && ./sdkmanager "build-tools;29.0.3" "platform-tools" "platforms;android-29" "sources;android-29"
ENV PATH "$PATH:${SDKROOT}/Android/sdk/platform-tools"
ENV PATH "$PATH:${SDKROOT}/Android/sdk/emulator"

# Download Flutter SDK
RUN git clone https://github.com/flutter/flutter.git -b stable
ENV PATH "$PATH:${SDKROOT}/flutter/bin"

# Run basic check to download Dark SDK
RUN flutter doctor
