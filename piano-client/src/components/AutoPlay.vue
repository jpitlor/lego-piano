<script setup lang="ts">
import { OpenSheetMusicDisplay } from "opensheetmusicdisplay";
import { onMounted, ref } from "vue";
import { FontAwesomeIcon } from "@fortawesome/vue-fontawesome";

const sheetMusic = ref<OpenSheetMusicDisplay>();

onMounted(async () => {
  sheetMusic.value = new OpenSheetMusicDisplay("sheet-music-container", {
    autoResize: true,
    backend: "svg",
    drawTitle: true,
  });
  await sheetMusic.value.load("/songs/MozaVeilSample.xml");
  sheetMusic.value.render();
});
</script>

<template>
  <div id="sheet-music-container" />
</template>

<style scoped>
#sheet-music-container {
  width: 100%;
  height: 100%;
  position: absolute;
  overflow: hidden;
}
</style>
