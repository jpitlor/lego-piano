<script setup lang="ts">
import { OpenSheetMusicDisplay } from "opensheetmusicdisplay";
import { onMounted, ref, watchEffect } from "vue";
import { store } from "../store.ts";

const osmd = ref<OpenSheetMusicDisplay>();

onMounted(async () => {
  osmd.value = new OpenSheetMusicDisplay("sheet-music-container", {
    autoResize: true,
    backend: "svg",
    drawTitle: false,
    drawComposer: false,
    drawLyricist: false,
    drawSubtitle: false,
    drawMetronomeMarks: false,
  });
});

watchEffect(async () => {
  if (!osmd.value || !store.file) {
    return;
  }

  await osmd.value.load(store.file);
  osmd.value.render();
  store.title = osmd.value.Sheet.Title.text;
});
</script>

<template>
  <div id="sheet-music-container" />
</template>

<style scoped>
#sheet-music-container {
  flex: 1;
}
</style>
