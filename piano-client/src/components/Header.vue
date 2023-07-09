<script setup lang="ts">
import { FontAwesomeIcon } from "@fortawesome/vue-fontawesome";
import { ref } from "vue";
import { PlayType } from "../helpers/PlayType.ts";
import Slider from "./Slider.vue";
import SongPicker from "./SongPicker.vue";

const isPlaying = ref(false);
const playType = ref(PlayType.AutoPlay);
const song = ref<any>("");

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
        <font-awesome-icon icon="fa-pause-circle" />
      </button>
      <button v-else @click="play">
        <font-awesome-icon icon="fa-play-circle" />
      </button>
    </div>
    <div>
      <span>{{ song?.name ?? song }}</span>
      <SongPicker @change="(s: string) => (song = s)" />
    </div>
    <div>
      <Slider
        left-icon="fa-user"
        right-icon="fa-computer"
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
</style>
