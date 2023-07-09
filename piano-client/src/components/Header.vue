<script setup lang="ts">
import { FontAwesomeIcon } from "@fortawesome/vue-fontawesome";
import { ref } from "vue";
import { PlayType } from "../helpers/PlayType.ts";
import Slider from "./Slider.vue";

const songs = import.meta.glob("../songs/*.xml", { eager: true, as: "url" });

console.log(songs);

const isPlaying = ref(false);
const playType = ref(PlayType.AutoPlay);

function play() {
  isPlaying.value = true;
}

function pause() {
  isPlaying.value = false;
}
</script>

<template>
  <div id="header">
    <div>
      <button v-if="isPlaying" @click="pause">
        <font-awesome-icon icon="fa-regular fa-pause-circle" />
      </button>
      <button v-else @click="play">
        <font-awesome-icon icon="fa-regular fa-play-circle" />
      </button>
    </div>
    <div>title</div>
    <div>
      <Slider
        left-icon="fa-regular fa-user"
        right-icon="fa-regular fa-computer"
        :value="playType"
        @change="(x: PlayType) => (playType = x)"
      />
    </div>
  </div>
</template>

<style lang="scss" scoped>
#header {
  display: flex;
  flex-direction: row;
  padding: 1rem;
  right: 0;
  left: 0;
  top: 0;
  position: absolute;
  z-index: 999;
  border-bottom: 1px solid black;

  :nth-child(2) {
    flex: 1;
    text-align: center;
  }
}

button {
  background: none;
  border: none;
  font-size: 1.5rem;
  cursor: pointer;
}
</style>
