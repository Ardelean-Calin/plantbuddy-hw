/// <reference types="web-bluetooth" />

export async function connectToPlantbuddy(): Promise<
  BluetoothRemoteGATTServer | undefined
> {
  const bleNavigator = window.navigator.bluetooth;
  let server: BluetoothRemoteGATTServer | undefined;

  if (window.isSecureContext) {
    const pbDevice = await bleNavigator.requestDevice({
      filters: [{ services: ["f4c2abcd-6e5f-48a2-b9b2-a4f762791d85"] }],
      optionalServices: ["f4c2abcd-6e5f-48a2-b9b2-a4f762791d85"],
    });
    server = await pbDevice.gatt?.connect();
  }

  return server;
}
