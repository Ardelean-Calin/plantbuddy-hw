<template>
  <div>
    <div>Landing Page {{ count }}</div>
    <button @click="increment">Increment</button>
  </div>
</template>

<script lang="ts">
import { Component, Prop, Vue } from "vue-property-decorator";

@Component
export default class LandingPage extends Vue {
  @Prop() private count = 0;

  increment(): void {
    this.count++;
  }
}
</script>

<style scoped></style>
