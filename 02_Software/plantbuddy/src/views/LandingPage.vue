<template>
  <div>
    <button @click="start">Start!</button>
  </div>
</template>

<script lang="ts">
import { Component, Prop, Vue } from "vue-property-decorator";
import { PlantBuddy } from "@/lib/plantbuddy";

let plantbuddy: PlantBuddy;

@Component
export default class LandingPage extends Vue {
  @Prop({ required: false }) private count!: number;

  mounted(): void {
    plantbuddy = new PlantBuddy();
  }

  start(): void {
    plantbuddy
      .searchAndPair()
      .then((server) => {
        server
          ?.getPrimaryService("f4c2abcd-6e5f-48a2-b9b2-a4f762791d85")
          .then((service) => {
            service
              .getCharacteristic("f4c20002-6e5f-48a2-b9b2-a4f762791d85")
              .then((characteristic) => {
                characteristic.readValue().then((data) => {
                  console.log(new Uint16Array(data.buffer));
                  return data.buffer;
                });
              });
          });
      })
      .then((value) => console.log(value))
      .catch((err) => console.error(err));
  }
}
</script>

<style scoped></style>
