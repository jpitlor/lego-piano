<script setup lang="ts">
import Slider from "./components/Slider.vue";
import { ref } from "vue";
import { PlayType } from "./helpers/PlayType.ts";
import AutoPlay from "./components/AutoPlay.vue";
import UserInput from "./components/UserInput.vue";

const playType = ref(PlayType.AutoPlay);
</script>

<template>
  <div id="header">
    <Slider
      left-icon="fa-regular fa-user"
      right-icon="fa-regular fa-computer"
      :value="playType"
      @change="(x: PlayType) => (playType = x)"
    />
  </div>
  <AutoPlay class="page" v-if="playType === PlayType.AutoPlay" />
  <UserInput class="page" v-else-if="playType === PlayType.UserInput" />
</template>

<style scoped>
#header {
  padding: 1rem;
  right: 0;
  position: absolute;
}

.page {
  position: absolute;
  width: 100%;
  height: 100%;
}
</style>
