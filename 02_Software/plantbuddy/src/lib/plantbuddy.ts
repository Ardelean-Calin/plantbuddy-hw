import "@/lib/bluetooth";
import { connectToPlantbuddy } from "@/lib/bluetooth";

export class PlantBuddy {
  /**
   * searchAndPair
   */
  public searchAndPair(): Promise<BluetoothRemoteGATTServer | undefined> {
    return connectToPlantbuddy();
  }
}
