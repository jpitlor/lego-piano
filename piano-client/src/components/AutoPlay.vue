<script setup>
import { OpenSheetMusicDisplay } from "opensheetmusicdisplay";
import { onMounted, ref } from "vue";
import song from "../assets/MozaVeilSample.xml";

const container = ref();

onMounted(() => {
  console.log(song);
  const osmd = new OpenSheetMusicDisplay(container.value, {
    autoResize: true,
    backend: "svg",
    drawTitle: true,
  });
  osmd.load(song).then(() => osmd.render());
});
</script>

<template>
  <div id="sheet-music-container" ref="container" />
</template>

<style scoped>
#sheet-music-container {
  width: 100%;
  height: 100%;
  position: absolute;
  overflow: hidden;
}
</style>
