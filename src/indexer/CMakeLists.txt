set(CMAKE_AUTOMOC ON)

add_executable(indexer)
# TODO: unnecessary dependency
set_target_properties(indexer PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY $<TARGET_FILE_DIR:source-inspector>
)

# TODO: not a good practice at all
target_include_directories(indexer PRIVATE
        codeblocks
        commandline
        commandline/commands
        component
        component/controller
        component/controller/helper
        component/view
        component/view/helper
        data
        data/bookmark
        data/fulltextsearch
        data/graph
        data/graph/token_component
        data/indexer
        data/indexer/interprocess
        data/indexer/interprocess/shared_types
        data/location
        data/name
        data/parser
        data/parser/cxx
        data/parser/cxx/name
        data/parser/cxx/name_resolver
        data/search
        data/storage
        data/storage/migration
        data/storage/sqlite
        data/storage/type
        data/tooltip
        file
        interprocess
        messaging
        messaging/filter_types
        messaging/type
        messaging/type/activation
        messaging/type/bookmark
        messaging/type/code
        messaging/type/custom_trail
        messaging/type/error
        messaging/type/focus
        messaging/type/graph
        messaging/type/history
        messaging/type/indexing
        messaging/type/plugin
        messaging/type/search
        messaging/type/tab
        migration
        path_detector
        path_detector/cxx_header
        paths
        project
        qt
        qt/element
        qt/element/bookmark
        qt/element/button
        qt/element/code
        qt/element/dialog
        qt/element/history
        qt/element/search
        qt/graphics
        qt/graphics/base
        qt/graphics/component
        qt/graphics/graph
        qt/network
        qt/project_wizard
        qt/project_wizard/content
        qt/project_wizard/content/path
        qt/project_wizard/content/paths
        qt/utility
        qt/view
        qt/window
        scheduling
        settings
        settings/migration
        settings/source_group
        settings/source_group/component
        settings/source_group/component/cxx
        settings/source_group/type
        text
        utility
        ${CMAKE_CURRENT_LIST_DIR}
)

target_sources(indexer PRIVATE
        main.cpp

        # TODO: code duplication with 'app'
        Application.cpp
        Application.h
        ApplicationArchitectureType.h
        ConfigManager.cpp
        ConfigManager.h
        CompilationDatabase.cpp
        CompilationDatabase.h
        IncludeDirective.cpp
        IncludeDirective.h
        IncludeProcessing.cpp
        IncludeProcessing.h
        LanguagePackage.h
        LanguagePackageCxx.cpp
        LanguagePackageCxx.h
        LanguagePackageManager.cpp
        LanguagePackageManager.h
        LowMemoryStringMap.h
        OrderedCache.h
        OsType.h
        ScopedFunctor.cpp
        ScopedFunctor.h
        SingleValueCache.h
        Status.h
        TimeStamp.cpp
        TimeStamp.h
        tracing.cpp
        tracing.h
        Tree.h
        types.h
        UnorderedCache.h
        utility.cpp
        utility.h
        utilityApp.cpp
        utilityApp.h
        utilityPathDetection.cpp
        utilityPathDetection.h
        utilityUuid.cpp
        utilityUuid.h
        Version.cpp
        Version.h

        # TODO: code duplication with 'app'
        codeblocks/CodeblocksCompiler.cpp
        codeblocks/CodeblocksCompiler.h
        codeblocks/CodeblocksCompilerVarType.cpp
        codeblocks/CodeblocksCompilerVarType.h
        codeblocks/CodeblocksProject.cpp
        codeblocks/CodeblocksProject.h
        codeblocks/CodeblocksTarget.cpp
        codeblocks/CodeblocksTarget.h
        codeblocks/CodeblocksTargetRelationType.cpp
        codeblocks/CodeblocksTargetRelationType.h
        codeblocks/CodeblocksUnit.cpp
        codeblocks/CodeblocksUnit.h

        # TODO: code duplication with 'app'
        component/controller/helper/ActivationListener.cpp
        component/controller/helper/ActivationListener.h
        component/controller/helper/BucketLayouter.cpp
        component/controller/helper/BucketLayouter.h
        component/controller/helper/DummyEdge.h
        component/controller/helper/DummyNode.h
        component/controller/helper/ListLayouter.cpp
        component/controller/helper/ListLayouter.h
        component/controller/helper/NetworkProtocolHelper.cpp
        component/controller/helper/NetworkProtocolHelper.h
        component/controller/helper/ScreenSearchInterfaces.h
        component/controller/helper/SnippetMerger.cpp
        component/controller/helper/SnippetMerger.h
        component/controller/helper/TrailLayouter.cpp
        component/controller/helper/TrailLayouter.h

        # TODO: code duplication with 'app'
        component/controller/ActivationController.cpp
        component/controller/ActivationController.h
        component/controller/BookmarkController.cpp
        component/controller/BookmarkController.h
        component/controller/CodeController.cpp
        component/controller/CodeController.h
        component/controller/Controller.cpp
        component/controller/Controller.h
        component/controller/CustomTrailController.cpp
        component/controller/CustomTrailController.h
        component/controller/ErrorController.cpp
        component/controller/ErrorController.h
        component/controller/GraphController.cpp
        component/controller/GraphController.h
        component/controller/IDECommunicationController.cpp
        component/controller/IDECommunicationController.h
        component/controller/RefreshController.cpp
        component/controller/RefreshController.h
        component/controller/ScreenSearchController.cpp
        component/controller/ScreenSearchController.h
        component/controller/SearchController.cpp
        component/controller/SearchController.h
        component/controller/StatusBarController.cpp
        component/controller/StatusBarController.h
        component/controller/StatusController.cpp
        component/controller/StatusController.h
        component/controller/TabsController.cpp
        component/controller/TabsController.h
        component/controller/TooltipController.cpp
        component/controller/TooltipController.h
        component/controller/UndoRedoController.cpp
        component/controller/UndoRedoController.h

        # TODO: code duplication with 'app'
        component/view/helper/CodeScrollParams.h
        component/view/helper/CodeSnippetParams.cpp
        component/view/helper/CodeSnippetParams.h
        component/view/BookmarkButtonsView.cpp
        component/view/BookmarkButtonsView.h
        component/view/BookmarkView.cpp
        component/view/BookmarkView.h
        component/view/CodeView.cpp
        component/view/CodeView.h
        component/view/CompositeView.cpp
        component/view/CompositeView.h
        component/view/CustomTrailView.h
        component/view/DialogView.cpp
        component/view/DialogView.h
        component/view/ErrorView.cpp
        component/view/ErrorView.h
        component/view/GraphView.cpp
        component/view/GraphView.h
        component/view/GraphViewStyle.cpp
        component/view/GraphViewStyle.h
        component/view/GraphViewStyleImpl.h
        component/view/MainView.cpp
        component/view/MainView.h
        component/view/RefreshView.cpp
        component/view/RefreshView.h
        component/view/ScreenSearchView.cpp
        component/view/ScreenSearchView.h
        component/view/SearchView.cpp
        component/view/SearchView.h
        component/view/StatusBarView.cpp
        component/view/StatusBarView.h
        component/view/StatusView.cpp
        component/view/StatusView.h
        component/view/TabbedView.cpp
        component/view/TabbedView.h
        component/view/TabsView.cpp
        component/view/TabsView.h
        component/view/TooltipView.cpp
        component/view/TooltipView.h
        component/view/UndoRedoView.cpp
        component/view/UndoRedoView.h
        component/view/View.cpp
        component/view/View.h
        component/view/ViewFactory.h
        component/view/ViewLayout.cpp
        component/view/ViewLayout.h
        component/view/ViewWidgetWrapper.cpp
        component/view/ViewWidgetWrapper.h

        # TODO: code duplication with 'app'
        component/Component.cpp
        component/Component.h
        component/ComponentFactory.cpp
        component/ComponentFactory.h
        component/ComponentManager.cpp
        component/ComponentManager.h
        component/NetworkFactory.cpp
        component/NetworkFactory.h
        component/Tab.cpp
        component/Tab.h
        component/TabId.cpp
        component/TabId.h

        # TODO: code duplication with 'app'
        data/bookmark/Bookmark.cpp
        data/bookmark/Bookmark.h
        data/bookmark/BookmarkCategory.cpp
        data/bookmark/BookmarkCategory.h
        data/bookmark/EdgeBookmark.cpp
        data/bookmark/EdgeBookmark.h
        data/bookmark/NodeBookmark.cpp
        data/bookmark/NodeBookmark.h

        # TODO: code duplication with 'app'
        data/fulltextsearch/FullTextSearchIndex.cpp
        data/fulltextsearch/FullTextSearchIndex.h
        data/fulltextsearch/SuffixArray.cpp
        data/fulltextsearch/SuffixArray.h

        # TODO: code duplication with 'app'
        data/graph/token_component/TokenComponent.cpp
        data/graph/token_component/TokenComponent.h
        data/graph/token_component/TokenComponentAbstraction.cpp
        data/graph/token_component/TokenComponentAbstraction.h
        data/graph/token_component/TokenComponentAccess.cpp
        data/graph/token_component/TokenComponentAccess.h
        data/graph/token_component/TokenComponentBundledEdges.cpp
        data/graph/token_component/TokenComponentBundledEdges.h
        data/graph/token_component/TokenComponentConst.cpp
        data/graph/token_component/TokenComponentConst.h
        data/graph/token_component/TokenComponentFilePath.cpp
        data/graph/token_component/TokenComponentFilePath.h
        data/graph/token_component/TokenComponentInheritanceChain.h
        data/graph/token_component/TokenComponentIsAmbiguous.h
        data/graph/token_component/TokenComponentStatic.cpp
        data/graph/token_component/TokenComponentStatic.h

        # TODO: code duplication with 'app'
        data/graph/Edge.cpp
        data/graph/Edge.h
        data/graph/ElementComponentKind.cpp
        data/graph/ElementComponentKind.h
        data/graph/Graph.cpp
        data/graph/Graph.h
        data/graph/Node.cpp
        data/graph/Node.h
        data/graph/Token.cpp
        data/graph/Token.h

        # TODO: code duplication with 'app'
        data/indexer/interprocess/shared_types/SharedIndexerCommand.cpp
        data/indexer/interprocess/shared_types/SharedIndexerCommand.h
        data/indexer/interprocess/shared_types/SharedIntermediateStorage.cpp
        data/indexer/interprocess/shared_types/SharedIntermediateStorage.h
        data/indexer/interprocess/shared_types/SharedStorageTypes.h

        # TODO: code duplication with 'app'
        data/indexer/interprocess/BaseInterprocessDataManager.cpp
        data/indexer/interprocess/BaseInterprocessDataManager.h
        data/indexer/interprocess/InterprocessIndexer.cpp
        data/indexer/interprocess/InterprocessIndexer.h
        data/indexer/interprocess/InterprocessIndexerCommandManager.cpp
        data/indexer/interprocess/InterprocessIndexerCommandManager.h
        data/indexer/interprocess/InterprocessIndexingStatusManager.cpp
        data/indexer/interprocess/InterprocessIndexingStatusManager.h
        data/indexer/interprocess/InterprocessIntermediateStorageManager.cpp
        data/indexer/interprocess/InterprocessIntermediateStorageManager.h

        # TODO: code duplication with 'app'
        data/indexer/CombinedIndexerCommandProvider.cpp
        data/indexer/CombinedIndexerCommandProvider.h
        data/indexer/Indexer.h
        data/indexer/IndexerBase.cpp
        data/indexer/IndexerBase.h
        data/indexer/IndexerCommand.cpp
        data/indexer/IndexerCommand.h
        data/indexer/IndexerCommandCustom.cpp
        data/indexer/IndexerCommandCustom.h
        data/indexer/IndexerCommandProvider.cpp
        data/indexer/IndexerCommandProvider.h
        data/indexer/IndexerCommandType.cpp
        data/indexer/IndexerCommandType.h
        data/indexer/IndexerComposite.cpp
        data/indexer/IndexerComposite.h
        data/indexer/IndexerStateInfo.h
        data/indexer/MemoryIndexerCommandProvider.cpp
        data/indexer/MemoryIndexerCommandProvider.h
        data/indexer/TaskBuildIndex.cpp
        data/indexer/TaskBuildIndex.h
        data/indexer/TaskExecuteCustomCommands.cpp
        data/indexer/TaskExecuteCustomCommands.h
        data/indexer/TaskFillIndexerCommandQueue.cpp
        data/indexer/TaskFillIndexerCommandQueue.h
        data/indexer/CxxIndexerCommandProvider.cpp
        data/indexer/CxxIndexerCommandProvider.h
        data/indexer/IndexerCommandCxx.cpp
        data/indexer/IndexerCommandCxx.h
        data/indexer/IndexerCxx.cpp
        data/indexer/IndexerCxx.h

        # TODO: code duplication with 'app'
        data/location/LocationType.cpp
        data/location/LocationType.h
        data/location/SourceLocation.cpp
        data/location/SourceLocation.h
        data/location/SourceLocationCollection.cpp
        data/location/SourceLocationCollection.h
        data/location/SourceLocationFile.cpp
        data/location/SourceLocationFile.h

        # TODO: code duplication with 'app'
        data/name/NameDelimiterType.cpp
        data/name/NameDelimiterType.h
        data/name/NameElement.cpp
        data/name/NameElement.h
        data/name/NameHierarchy.cpp
        data/name/NameHierarchy.h

        # TODO: code duplication with 'app'
        data/parser/AccessKind.cpp
        data/parser/AccessKind.h
        data/parser/ParseLocation.cpp
        data/parser/ParseLocation.h
        data/parser/Parser.cpp
        data/parser/Parser.h
        data/parser/ParserClient.h
        data/parser/ParserClientImpl.cpp
        data/parser/ParserClientImpl.h
        data/parser/ReferenceKind.cpp
        data/parser/ReferenceKind.h
        data/parser/SymbolKind.cpp
        data/parser/SymbolKind.h
        data/parser/TaskParseWrapper.cpp
        data/parser/TaskParseWrapper.h

        # TODO: code duplication with 'app'
        data/parser/cxx/name/CxxDeclName.cpp
        data/parser/cxx/name/CxxDeclName.h
        data/parser/cxx/name/CxxFunctionDeclName.cpp
        data/parser/cxx/name/CxxFunctionDeclName.h
        data/parser/cxx/name/CxxName.cpp
        data/parser/cxx/name/CxxName.h
        data/parser/cxx/name/CxxQualifierFlags.cpp
        data/parser/cxx/name/CxxQualifierFlags.h
        data/parser/cxx/name/CxxStaticFunctionDeclName.cpp
        data/parser/cxx/name/CxxStaticFunctionDeclName.h
        data/parser/cxx/name/CxxTypeName.cpp
        data/parser/cxx/name/CxxTypeName.h
        data/parser/cxx/name/CxxVariableDeclName.cpp
        data/parser/cxx/name/CxxVariableDeclName.h

        # TODO: code duplication with 'app'
        data/parser/cxx/name_resolver/CxxDeclNameResolver.cpp
        data/parser/cxx/name_resolver/CxxDeclNameResolver.h
        data/parser/cxx/name_resolver/CxxNameResolver.cpp
        data/parser/cxx/name_resolver/CxxNameResolver.h
        data/parser/cxx/name_resolver/CxxSpecifierNameResolver.cpp
        data/parser/cxx/name_resolver/CxxSpecifierNameResolver.h
        data/parser/cxx/name_resolver/CxxTemplateArgumentNameResolver.cpp
        data/parser/cxx/name_resolver/CxxTemplateArgumentNameResolver.h
        data/parser/cxx/name_resolver/CxxTemplateParameterStringResolver.cpp
        data/parser/cxx/name_resolver/CxxTemplateParameterStringResolver.h
        data/parser/cxx/name_resolver/CxxTypeNameResolver.cpp
        data/parser/cxx/name_resolver/CxxTypeNameResolver.h

        # TODO: code duplication with 'app'
        data/parser/cxx/ASTAction.cpp
        data/parser/cxx/ASTAction.h
        data/parser/cxx/ASTConsumer.cpp
        data/parser/cxx/ASTConsumer.h
        data/parser/cxx/CanonicalFilePathCache.cpp
        data/parser/cxx/CanonicalFilePathCache.h
        data/parser/cxx/CommentHandler.cpp
        data/parser/cxx/CommentHandler.h
        data/parser/cxx/ClangInvocationInfo.cpp
        data/parser/cxx/ClangInvocationInfo.h
        data/parser/cxx/CxxAstVisitor.cpp
        data/parser/cxx/CxxAstVisitor.h
        data/parser/cxx/CxxAstVisitorComponent.cpp
        data/parser/cxx/CxxAstVisitorComponent.h
        data/parser/cxx/CxxAstVisitorComponentBraceRecorder.cpp
        data/parser/cxx/CxxAstVisitorComponentBraceRecorder.h
        data/parser/cxx/CxxAstVisitorComponentContext.cpp
        data/parser/cxx/CxxAstVisitorComponentContext.h
        data/parser/cxx/CxxAstVisitorComponentDeclRefKind.cpp
        data/parser/cxx/CxxAstVisitorComponentDeclRefKind.h
        data/parser/cxx/CxxAstVisitorComponentImplicitCode.cpp
        data/parser/cxx/CxxAstVisitorComponentImplicitCode.h
        data/parser/cxx/CxxAstVisitorComponentIndexer.cpp
        data/parser/cxx/CxxAstVisitorComponentIndexer.h
        data/parser/cxx/CxxAstVisitorComponentTypeRefKind.cpp
        data/parser/cxx/CxxAstVisitorComponentTypeRefKind.h
        data/parser/cxx/CxxCompilationDatabaseSingle.cpp
        data/parser/cxx/CxxCompilationDatabaseSingle.h
        data/parser/cxx/CxxContext.cpp
        data/parser/cxx/CxxContext.h
        data/parser/cxx/CxxDiagnosticConsumer.cpp
        data/parser/cxx/CxxDiagnosticConsumer.h
        data/parser/cxx/CxxParser.cpp
        data/parser/cxx/CxxParser.h
        data/parser/cxx/CxxVerboseAstVisitor.cpp
        data/parser/cxx/CxxVerboseAstVisitor.h
        data/parser/cxx/GeneratePCHAction.cpp
        data/parser/cxx/GeneratePCHAction.h
        data/parser/cxx/PreprocessorCallbacks.cpp
        data/parser/cxx/PreprocessorCallbacks.h
        data/parser/cxx/SingleFrontendActionFactory.cpp
        data/parser/cxx/SingleFrontendActionFactory.h
        data/parser/cxx/utilityClang.cpp
        data/parser/cxx/utilityClang.h

        # TODO: code duplication with 'app'
        data/search/SearchIndex.cpp
        data/search/SearchIndex.h
        data/search/SearchMatch.cpp
        data/search/SearchMatch.h

        # TODO: code duplication with 'app'
        data/storage/migration/SqliteStorageMigration.cpp
        data/storage/migration/SqliteStorageMigration.h
        data/storage/migration/SqliteStorageMigrationLambda.cpp
        data/storage/migration/SqliteStorageMigrationLambda.h
        data/storage/migration/SqliteStorageMigrator.h

        # TODO: code duplication with 'app'
        data/storage/sqlite/SqliteBookmarkStorage.cpp
        data/storage/sqlite/SqliteBookmarkStorage.h
        data/storage/sqlite/SqliteDatabaseIndex.cpp
        data/storage/sqlite/SqliteDatabaseIndex.h
        data/storage/sqlite/SqliteIndexStorage.cpp
        data/storage/sqlite/SqliteIndexStorage.h
        data/storage/sqlite/SqliteStorage.cpp
        data/storage/sqlite/SqliteStorage.h

        # TODO: code duplication with 'app'
        data/storage/type/StorageBookmarkCategory.h
        data/storage/type/StorageBookmark.h
        data/storage/type/StorageBookmarkedEdge.h
        data/storage/type/StorageBookmarkedNode.h
        data/storage/type/StorageComponentAccess.h
        data/storage/type/StorageEdge.h
        data/storage/type/StorageElementComponent.h
        data/storage/type/StorageError.h
        data/storage/type/StorageFile.h
        data/storage/type/StorageLocalSymbol.h
        data/storage/type/StorageNode.h
        data/storage/type/StorageOccurrence.h
        data/storage/type/StorageSourceLocation.h
        data/storage/type/StorageSymbol.h

        # TODO: code duplication with 'app'
        data/storage/IntermediateStorage.cpp
        data/storage/IntermediateStorage.h
        data/storage/PersistentStorage.cpp
        data/storage/PersistentStorage.h
        data/storage/Storage.cpp
        data/storage/Storage.h
        data/storage/StorageAccess.h
        data/storage/StorageAccessProxy.cpp
        data/storage/StorageAccessProxy.h
        data/storage/StorageCache.cpp
        data/storage/StorageCache.h
        data/storage/StorageProvider.cpp
        data/storage/StorageProvider.h
        data/storage/StorageStats.h

        # TODO: code duplication with 'app'
        data/tooltip/TooltipInfo.h
        data/tooltip/TooltipOrigin.h

        # TODO: code duplication with 'app'
        data/DefinitionKind.cpp
        data/DefinitionKind.h
        data/ErrorCountInfo.h
        data/ErrorFilter.h
        data/ErrorInfo.h
        data/GroupType.cpp
        data/GroupType.h
        data/HierarchyCache.cpp
        data/HierarchyCache.h
        data/NodeKind.cpp
        data/NodeKind.h
        data/NodeType.cpp
        data/NodeType.h
        data/NodeTypeSet.cpp
        data/NodeTypeSet.h
        data/TaskCleanStorage.cpp
        data/TaskCleanStorage.h
        data/TaskFinishParsing.cpp
        data/TaskFinishParsing.h
        data/TaskInjectStorage.cpp
        data/TaskInjectStorage.h
        data/TaskMergeStorages.cpp
        data/TaskMergeStorages.h

        # TODO: code duplication with 'app'
        file/FileInfo.cpp
        file/FileInfo.h
        file/FileManager.cpp
        file/FileManager.h
        file/FilePath.cpp
        file/FilePath.h
        file/FilePathFilter.cpp
        file/FilePathFilter.h
        file/FileRegister.cpp
        file/FileRegister.h
        file/FileSystem.cpp
        file/FileSystem.h
        file/FileTree.cpp
        file/FileTree.h
        file/utilityFile.cpp
        file/utilityFile.h

        # TODO: code duplication with 'app'
        interprocess/SharedMemory.cpp
        interprocess/SharedMemory.h
        interprocess/SharedMemoryGarbageCollector.cpp
        interprocess/SharedMemoryGarbageCollector.h

        # TODO: code duplication with 'app'
        messaging/filter_types/MessageFilterErrorCountUpdate.h
        messaging/filter_types/MessageFilterFocusInOut.h
        messaging/filter_types/MessageFilterSearchAutocomplete.h

        # TODO: code duplication with 'app'
        messaging/type/activation/MessageActivateBase.h
        messaging/type/activation/MessageActivateErrors.h
        messaging/type/activation/MessageActivateFullTextSearch.h
        messaging/type/activation/MessageActivateLegend.h
        messaging/type/activation/MessageActivateOverview.h
        messaging/type/activation/MessageActivateTokens.h
        messaging/type/activation/MessageActivateTrail.h

        # TODO: code duplication with 'app'
        messaging/type/bookmark/MessageBookmarkActivate.h
        messaging/type/bookmark/MessageBookmarkBrowse.h
        messaging/type/bookmark/MessageBookmarkButtonState.h
        messaging/type/bookmark/MessageBookmarkCreate.h
        messaging/type/bookmark/MessageBookmarkDelete.h
        messaging/type/bookmark/MessageBookmarkEdit.h

        # TODO: code duplication with 'app'
        messaging/type/code/MessageActivateFile.h
        messaging/type/code/MessageActivateLocalSymbols.h
        messaging/type/code/MessageActivateSourceLocations.h
        messaging/type/code/MessageActivateTokenIds.h
        messaging/type/code/MessageChangeFileView.h
        messaging/type/code/MessageCodeReference.h
        messaging/type/code/MessageCodeShowDefinition.h
        messaging/type/code/MessageScrollCode.h
        messaging/type/code/MessageScrollToLine.h
        messaging/type/code/MessageShowReference.h
        messaging/type/code/MessageShowScope.h

        # TODO: code duplication with 'app'
        messaging/type/custom_trail/MessageCustomTrailShow.h

        messaging/type/error/MessageErrorCountClear.h
        messaging/type/error/MessageErrorCountUpdate.h
        messaging/type/error/MessageErrorsAll.h
        messaging/type/error/MessageErrorsForFile.h
        messaging/type/error/MessageErrorsHelpMessage.h
        messaging/type/error/MessageShowError.h

        messaging/type/focus/MessageFocusChanged.h
        messaging/type/focus/MessageFocusedSearchView.h
        messaging/type/focus/MessageFocusIn.h
        messaging/type/focus/MessageFocusOut.h
        messaging/type/focus/MessageFocusView.h

        # TODO: code duplication with 'app'
        messaging/type/graph/MessageActivateEdge.h
        messaging/type/graph/MessageActivateNodes.h
        messaging/type/graph/MessageActivateTrailEdge.h
        messaging/type/graph/MessageDeactivateEdge.h
        messaging/type/graph/MessageGraphNodeBundleSplit.h
        messaging/type/graph/MessageGraphNodeExpand.h
        messaging/type/graph/MessageGraphNodeHide.h
        messaging/type/graph/MessageGraphNodeMove.h
        messaging/type/graph/MessageScrollGraph.h
        messaging/type/graph/MessageSaveAsImage.h

        # TODO: code duplication with 'app'
        messaging/type/history/MessageHistoryToPosition.h
        messaging/type/history/MessageHistoryRedo.h
        messaging/type/history/MessageHistoryUndo.h

        # TODO: code duplication with 'app'
        messaging/type/indexing/MessageIndexingFinished.h
        messaging/type/indexing/MessageIndexingInterrupted.h
        messaging/type/indexing/MessageIndexingShowDialog.h
        messaging/type/indexing/MessageIndexingStarted.h
        messaging/type/indexing/MessageIndexingStatus.h

        # TODO: code duplication with 'app'
        messaging/type/plugin/MessageIDECreateCDB.h
        messaging/type/plugin/MessageMoveIDECursor.h
        messaging/type/plugin/MessagePingReceived.h
        messaging/type/plugin/MessagePluginPortChange.h

        # TODO: code duplication with 'app'
        messaging/type/search/MessageFind.h
        messaging/type/search/MessageSearch.h
        messaging/type/search/MessageSearchAutocomplete.h

        # TODO: code duplication with 'app'
        messaging/type/tab/MessageTabClose.h
        messaging/type/tab/MessageTabOpen.h
        messaging/type/tab/MessageTabOpenWith.h
        messaging/type/tab/MessageTabSelect.h
        messaging/type/tab/MessageTabState.h

        # TODO: code duplication with 'app'
        messaging/type/MessageActivateWindow.h
        messaging/type/MessageClearStatusView.h
        messaging/type/MessageCloseProject.h
        messaging/type/MessageFlushUpdates.h
        messaging/type/MessageLoadProject.h
        messaging/type/MessageLogFilterChanged.h
        messaging/type/MessageProjectEdit.h
        messaging/type/MessageProjectNew.h
        messaging/type/MessageQuitApplication.h
        messaging/type/MessageRefresh.h
        messaging/type/MessageRefreshUI.h
        messaging/type/MessageRefreshUIState.h
        messaging/type/MessageResetZoom.h
        messaging/type/MessageShowStatus.h
        messaging/type/MessageStatus.cpp
        messaging/type/MessageStatus.h
        messaging/type/MessageStatusFilterChanged.h
        messaging/type/MessageSwitchColorScheme.h
        messaging/type/MessageTooltipHide.h
        messaging/type/MessageTooltipShow.h
        messaging/type/MessageWindowChanged.h
        messaging/type/MessageWindowClosed.h
        messaging/type/MessageWindowFocus.h
        messaging/type/MessageZoom.h

        # TODO: code duplication with 'app'
        messaging/Message.h
        messaging/MessageBase.cpp
        messaging/MessageBase.h
        # messaging/MessageFilter.h
        # messaging/MessageListener.h
        messaging/MessageListenerBase.cpp
        messaging/MessageListenerBase.h
        messaging/MessageQueue.cpp
        messaging/MessageQueue.h

        # TODO: code duplication with 'app'
        path_detector/cxx_header/CxxFrameworkPathDetector.cpp
        path_detector/cxx_header/CxxFrameworkPathDetector.h
        path_detector/cxx_header/CxxHeaderPathDetector.cpp
        path_detector/cxx_header/CxxHeaderPathDetector.h
        path_detector/cxx_header/CxxVs10To14HeaderPathDetector.cpp
        path_detector/cxx_header/CxxVs10To14HeaderPathDetector.h
        path_detector/cxx_header/CxxVs15HeaderPathDetector.cpp
        path_detector/cxx_header/CxxVs15HeaderPathDetector.h
        path_detector/cxx_header/utilityCxxHeaderDetection.cpp
        path_detector/cxx_header/utilityCxxHeaderDetection.h

        # TODO: code duplication with 'app'
        path_detector/CombinedPathDetector.cpp
        path_detector/CombinedPathDetector.h
        path_detector/PathDetector.cpp
        path_detector/PathDetector.h

        # TODO: code duplication with 'app'
        paths/AppPath.cpp
        paths/AppPath.h
        paths/ResourcePaths.cpp
        paths/ResourcePaths.h
        paths/UserPaths.cpp
        paths/UserPaths.h

        # TODO: code duplication with 'app'
        project/Project.cpp
        project/Project.h
        project/RefreshInfo.h
        project/RefreshInfoGenerator.h
        project/RefreshInfoGenerator.cpp
        project/SourceGroup.cpp
        project/SourceGroup.h
        project/SourceGroupCustomCommand.cpp
        project/SourceGroupCustomCommand.h
        project/SourceGroupFactory.cpp
        project/SourceGroupFactory.h
        project/SourceGroupFactoryModule.cpp
        project/SourceGroupFactoryModule.h
        project/SourceGroupFactoryModuleCustom.cpp
        project/SourceGroupFactoryModuleCustom.h
        project/SourceGroupCxxCdb.cpp
        project/SourceGroupCxxCdb.h
        project/SourceGroupCxxCodeblocks.cpp
        project/SourceGroupCxxCodeblocks.h
        project/SourceGroupCxxEmpty.cpp
        project/SourceGroupCxxEmpty.h
        project/SourceGroupFactoryModuleCxx.cpp
        project/SourceGroupFactoryModuleCxx.h
        project/utilitySourceGroupCxx.cpp
        project/utilitySourceGroupCxx.h

        # TODO: why is Qt here when this is a console application

        # TODO: code duplication with 'app'
        qt/utility/QtHelpButtonInfo.cpp
        qt/utility/QtHelpButtonInfo.h
        qt/utility/QtThreadedFunctor.h

        # TODO: code duplication with 'app'
        scheduling/Blackboard.cpp
        scheduling/Blackboard.h
        scheduling/Task.cpp
        scheduling/Task.h
        scheduling/TaskDecorator.cpp
        scheduling/TaskDecorator.h
        scheduling/TaskDecoratorRepeat.cpp
        scheduling/TaskDecoratorRepeat.h
        scheduling/TaskDecoratorDelay.cpp
        scheduling/TaskDecoratorDelay.h
        scheduling/TaskFindKeyOnBlackboard.cpp
        scheduling/TaskFindKeyOnBlackboard.h
        scheduling/TaskGroup.cpp
        scheduling/TaskGroup.h
        scheduling/TaskGroupParallel.cpp
        scheduling/TaskGroupParallel.h
        scheduling/TaskGroupSelector.cpp
        scheduling/TaskGroupSelector.h
        scheduling/TaskGroupSequence.cpp
        scheduling/TaskGroupSequence.h
        scheduling/TaskLambda.cpp
        scheduling/TaskLambda.h
        scheduling/TaskManager.cpp
        scheduling/TaskManager.h
        scheduling/TaskReturnSuccessIf.h
        scheduling/TaskRunner.cpp
        scheduling/TaskRunner.h
        scheduling/TaskScheduler.cpp
        scheduling/TaskScheduler.h
        scheduling/TaskSetValue.h

        # TODO: code duplication with 'app'
        settings/migration/SettingsMigration.cpp
        settings/migration/SettingsMigration.h
        settings/migration/SettingsMigrationDeleteKey.cpp
        settings/migration/SettingsMigrationDeleteKey.h
        settings/migration/SettingsMigrationLambda.cpp
        settings/migration/SettingsMigrationLambda.h
        settings/migration/SettingsMigrationMoveKey.cpp
        settings/migration/SettingsMigrationMoveKey.h
        settings/migration/SettingsMigrator.h

        # TODO: code duplication with 'app'
        settings/source_group/component/SourceGroupSettingsWithCustomCommand.cpp
        settings/source_group/component/SourceGroupSettingsWithCustomCommand.h
        settings/source_group/component/SourceGroupSettingsWithExcludeFilters.cpp
        settings/source_group/component/SourceGroupSettingsWithExcludeFilters.h
        settings/source_group/component/SourceGroupSettingsWithSourceExtensions.cpp
        settings/source_group/component/SourceGroupSettingsWithSourceExtensions.h
        settings/source_group/component/SourceGroupSettingsWithSourceExtensionsEmpty.h
        settings/source_group/component/SourceGroupSettingsWithSourcePaths.cpp
        settings/source_group/component/SourceGroupSettingsWithSourcePaths.h

        # TODO: code duplication with 'app'
        settings/source_group/component/cxx/SourceGroupSettingsWithCppStandard.cpp
        settings/source_group/component/cxx/SourceGroupSettingsWithCppStandard.h
        settings/source_group/component/cxx/SourceGroupSettingsWithCStandard.cpp
        settings/source_group/component/cxx/SourceGroupSettingsWithCStandard.h
        settings/source_group/component/cxx/SourceGroupSettingsWithCxxCdbPath.cpp
        settings/source_group/component/cxx/SourceGroupSettingsWithCxxCdbPath.h
        settings/source_group/component/cxx/SourceGroupSettingsWithCxxCodeblocksPath.cpp
        settings/source_group/component/cxx/SourceGroupSettingsWithCxxCodeblocksPath.h
        settings/source_group/component/cxx/SourceGroupSettingsWithCxxCrossCompilationOptions.cpp
        settings/source_group/component/cxx/SourceGroupSettingsWithCxxCrossCompilationOptions.h
        settings/source_group/component/cxx/SourceGroupSettingsWithCxxPathsAndFlags.cpp
        settings/source_group/component/cxx/SourceGroupSettingsWithCxxPathsAndFlags.h
        settings/source_group/component/cxx/SourceGroupSettingsWithCxxPchOptions.cpp
        settings/source_group/component/cxx/SourceGroupSettingsWithCxxPchOptions.h
        settings/source_group/component/cxx/SourceGroupSettingsWithIndexedHeaderPaths.cpp
        settings/source_group/component/cxx/SourceGroupSettingsWithIndexedHeaderPaths.h
        settings/source_group/component/cxx/SourceGroupSettingsWithSourceExtensionsC.h
        settings/source_group/component/cxx/SourceGroupSettingsWithSourceExtensionsCpp.h

        # TODO: code duplication with 'app'
        settings/source_group/type/SourceGroupSettingsCEmpty.h
        settings/source_group/type/SourceGroupSettingsCppEmpty.h
        settings/source_group/type/SourceGroupSettingsCustomCommand.h
        settings/source_group/type/SourceGroupSettingsCxxCdb.h
        settings/source_group/type/SourceGroupSettingsCxxCodeblocks.h
        settings/source_group/type/SourceGroupSettingsUnloadable.cpp
        settings/source_group/type/SourceGroupSettingsUnloadable.h

        # TODO: code duplication with 'app'
        settings/source_group/SourceGroupSettings.cpp
        settings/source_group/SourceGroupSettings.h
        settings/source_group/SourceGroupSettingsBase.h
        settings/source_group/SourceGroupSettingsWithComponents.h
        settings/source_group/SourceGroupStatusType.cpp
        settings/source_group/SourceGroupStatusType.h
        settings/source_group/SourceGroupType.cpp
        settings/source_group/SourceGroupType.h

        # TODO: code duplication with 'app'
        settings/ApplicationSettings.cpp
        settings/ApplicationSettings.h
        settings/ColorScheme.cpp
        settings/ColorScheme.h
        settings/LanguageType.cpp
        settings/LanguageType.h
        settings/ProjectSettings.cpp
        settings/ProjectSettings.h
        settings/Settings.cpp
        settings/Settings.h

        # TODO: code duplication with 'app'
        text/TextAccess.cpp
        text/TextAccess.h

        # TODO: code duplication with 'app'
        utility/TextCodec.cpp
        utility/TextCodec.h
        utility/utilityString.cpp
        utility/utilityString.h
)

## Dependencies
##
set(Boost_USE_MULTITHREAD ON)
set(Boost_USE_STATIC_LIBS ON CACHE BOOL "Set to ON to force the use of the static libraries.")
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.67 COMPONENTS system program_options filesystem date_time REQUIRED)

find_package(tinyxml CONFIG REQUIRED)
find_package(Qt5 "5.12.0" COMPONENTS Widgets Network REQUIRED)

find_package(Clang REQUIRED)
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(HandleLLVMOptions)

llvm_map_components_to_libnames(llvm_libs
        Analysis
        Core
        ExecutionEngine
        LibDriver
        Passes
        Option
        Support)

foreach (LLVM_TARGET ${LLVM_TARGETS_TO_BUILD})
    list(APPEND llvm_libs "LLVM${LLVM_TARGET}CodeGen")
    list(APPEND llvm_libs "LLVM${LLVM_TARGET}AsmParser")
endforeach ()

target_compile_definitions(indexer PRIVATE ${LLVM_DEFINITIONS})

# TODO: verify
if (WIN32)
    # hide the console when running a release build.
    set_target_properties(indexer PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE /DEBUG:FASTLINK")
    set_target_properties(indexer PROPERTIES COMPILE_DEFINITIONS_DEBUG "_CONSOLE")
    set_target_properties(indexer PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:CONSOLE")
    set_target_properties(indexer PROPERTIES COMPILE_DEFINITIONS_RELWITHDEBINFO "_CONSOLE")
    set_target_properties(indexer PROPERTIES LINK_FLAGS_RELEASE "/ENTRY:\"mainCRTStartup\" /SUBSYSTEM:WINDOWS /DEBUG")
    set_target_properties(indexer PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:WINDOWS")
endif ()

target_link_libraries(indexer PRIVATE enable_compiler_warnings)
target_link_libraries(indexer PRIVATE source-inspector::math)
target_link_libraries(indexer PRIVATE source-inspector::logging)
target_link_libraries(indexer PRIVATE clangASTMatchers)
target_link_libraries(indexer PRIVATE clangFrontend)
target_link_libraries(indexer PRIVATE clangSerialization)
target_link_libraries(indexer PRIVATE clangDriver)
target_link_libraries(indexer PRIVATE clangTooling)
target_link_libraries(indexer PRIVATE clangParse)
target_link_libraries(indexer PRIVATE clangSema)
target_link_libraries(indexer PRIVATE clangStaticAnalyzerFrontend)
target_link_libraries(indexer PRIVATE clangStaticAnalyzerCheckers)
target_link_libraries(indexer PRIVATE clangStaticAnalyzerCore)
target_link_libraries(indexer PRIVATE clangAnalysis)
target_link_libraries(indexer PRIVATE clangRewriteFrontend)
target_link_libraries(indexer PRIVATE clangEdit)
target_link_libraries(indexer PRIVATE clangAST)
target_link_libraries(indexer PRIVATE clangLex)
target_link_libraries(indexer PRIVATE clangBasic)
target_link_libraries(indexer PRIVATE ${llvm_libs})
target_link_libraries(indexer PRIVATE Boost::boost)
target_link_libraries(indexer PRIVATE Boost::filesystem)
target_link_libraries(indexer PRIVATE Qt5::Widgets)
target_link_libraries(indexer PRIVATE Qt5::Network)
target_link_libraries(indexer PRIVATE unofficial-tinyxml::unofficial-tinyxml)
target_link_libraries(indexer PRIVATE external::cppsqlite3)

# TODO: verify
if (APPLE)
    find_library(CORE_FOUNDATION CoreFoundation)
    target_link_libraries(indexer PRIVATE ${CORE_FOUNDATION})
endif ()
