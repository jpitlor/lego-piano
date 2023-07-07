<script setup lang="ts">
import { PlayType } from "../helpers/PlayType.ts";
import { FontAwesomeIcon } from "@fortawesome/vue-fontawesome";

const props = defineProps<{
  leftIcon: string;
  rightIcon: string;
  value: PlayType;
}>();
const emit = defineEmits<{ (e: "change", value: PlayType): void }>();

function togglePlayType() {
  if (props.value === PlayType.UserInput) {
    emit("change", PlayType.AutoPlay);
  } else {
    emit("change", PlayType.UserInput);
  }
}
</script>

<template>
  <div
    class="slider"
    :class="{ right: value === PlayType.AutoPlay }"
    @click="togglePlayType"
  >
    <font-awesome-icon :icon="leftIcon" class="left-icon" />
    <div class="ramp" />
    <div class="handle" />
    <font-awesome-icon :icon="rightIcon" class="right-icon" />
  </div>
</template>

<style scoped>
.left-icon {
  display: inline-block;
  margin-right: 1rem;
}

.right-icon {
  display: inline-block;
  margin-left: 1rem;
}

.slider {
  position: relative;
  display: inline-block;
}

.ramp {
  display: inline-block;
  background: #ccc;
  height: 1rem;
  width: 2.5rem;
  border-radius: 15px;
}

.handle {
  background: #444;
  border-radius: 100%;
  position: absolute;
  width: 1.5rem;
  height: 1.5rem;
  left: 1.5rem;
  top: -0.25rem;
  transition: ease-in-out 0.15s;
}

.right .handle {
  left: 3.5rem;
}
</style>
